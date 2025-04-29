struct State {
    int row;
    int col;
    int dist;
    string path;
    
    State(int r, int c, int d, const string &p)
        : row(r), col(c), dist(d), path(p) {}
};

// Custom comparator for min-heap:
// 1) Compare distance
// 2) If tie, compare path lexicographically
struct Compare {
    bool operator()(const State &a, const State &b) const {
        if (a.dist == b.dist) {
            return a.path > b.path; // smaller lex. path first => a.path < b.path => return a.path> b.path
        }
        return a.dist > b.dist;     // smaller distance first
    }
};

class Solution {
private:
    // 4 directions: left, up, right, down
    vector<vector<int>> directions = {{0,-1},{-1,0},{0,1},{1,0}};
    // matching direction strings
    vector<string> textDirections = {"l","u","r","d"};

    // check if (r,c) is valid + not a wall
    bool valid(int r, int c, const vector<vector<int>> &maze) {
        int m = maze.size(), n = maze[0].size();
        return (r >= 0 && r < m && c >= 0 && c < n && maze[r][c] == 0);
    }

    // move ball from (row,col) in each direction until hitting a wall or the hole
    vector<State> getNeighbors(int row, int col,
                               const vector<vector<int>> &maze,
                               const vector<int> &hole)
    {
        vector<State> neighbors;
        int m = maze.size(), n = maze[0].size();
        
        for (int i = 0; i < 4; i++) {
            int dy = directions[i][0];
            int dx = directions[i][1];
            string dirChar = textDirections[i];

            int currRow = row, currCol = col;
            int dist = 0;

            // roll the ball
            while (valid(currRow + dy, currCol + dx, maze)) {
                currRow += dy;
                currCol += dx;
                dist++;
                // if we hit the hole, stop
                if (currRow == hole[0] && currCol == hole[1]) {
                    break;
                }
            }
            // we add a neighbor: ended at (currRow, currCol) after 'dist' steps
            neighbors.push_back(State(currRow, currCol, dist, dirChar));
        }
        return neighbors;
    }

public:
    string findShortestWay(vector<vector<int>>& maze,
                           vector<int>& ball,
                           vector<int>& hole)
    {
        int m = maze.size(), n = maze[0].size();
        // A visited array for each cell. We do not store distance here,
        // because we store expansions in the priority queue. But we can store a "visited" to skip expansions
        // that have come with a better dist previously. Alternatively, we might do dist array
        // but let's keep it simpler to the original approach.
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        // Priority queue (min-heap) with the Compare struct
        priority_queue<State, vector<State>, Compare> pq;
        // start from (ball[0], ball[1]) with distance=0, path=""
        pq.push(State(ball[0], ball[1], 0, ""));

        while (!pq.empty()) {
            State curr = pq.top();
            pq.pop();

            int r = curr.row, c = curr.col;
            // if we've processed this cell before, skip
            if (seen[r][c]) continue;

            // if it's the hole, return path
            if (r == hole[0] && c == hole[1]) {
                return curr.path;
            }

            // mark as visited
            seen[r][c] = true;

            // expand neighbors
            vector<State> nbrs = getNeighbors(r, c, maze, hole);
            for (auto &ns : nbrs) {
                int nr = ns.row, nc = ns.col;
                int steps = ns.dist;
                string dirChar = ns.path; // single char like "l","u","r","d"

                if (!seen[nr][nc]) {
                    // push new state with dist = curr.dist + steps
                    // path = curr.path + dirChar
                    pq.push(State(nr, nc, curr.dist + steps, curr.path + dirChar));
                }
            }
        }
        // if we never reach the hole
        return "impossible";
    }
};
