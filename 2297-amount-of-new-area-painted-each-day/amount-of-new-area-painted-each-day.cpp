
class UnionFind
{
    private:
        vector<int> parent;

    public:
        UnionFind(int n)
        {
            parent.resize(n);
            iota(begin(parent), end(parent), 0);
        }
    
        int find_parent(int x)
        {
            if (parent[x] == x)
            {
                return x;
            }
            return parent[x] = find_parent(parent[x]);
        }

        void merge(int x, int y)
        {
            parent[x] = find_parent(y);

        }
};


class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {

        // return solve_set(paint);

        return solve_dsu(paint);
        
    }

    vector<int> solve_dsu(vector<vector<int>>& paint)
    {

        set<int> x_coordinates_set;
        // take unique x-coordiantes of paint
        for (auto& paint : paint)
        {
            x_coordinates_set.insert(paint[0]);
            x_coordinates_set.insert(paint[1]);
        }

        vector<int> x_coordinates(x_coordinates_set.begin(), x_coordinates_set.end());

        int n = x_coordinates.size();
        
        // map x_coordinates to indixes for DSU
        unordered_map<int, int> x_coordinates_to_indixes;
        for (int i=0; i< n; i++)
        {
            x_coordinates_to_indixes[x_coordinates[i]] = i;
        }

        vector<int> result;
        UnionFind uf(n);

        for (auto& pt : paint)
        {
            int left = x_coordinates_to_indixes[pt[0]];
            int right = x_coordinates_to_indixes[pt[1]];

            int painted_area = 0;

            int new_left = uf.find_parent(left);

            while (new_left < right)
            {
                painted_area += x_coordinates[new_left + 1] - x_coordinates[new_left];

                // merge new_left
                uf.merge(new_left, right);

                new_left = uf.find_parent(new_left + 1);
            }
            result.push_back(painted_area);
        }

        return result;
    }

    // TLE
    vector<int> solve_set(vector<vector<int>>& paint)
    {
        vector<int> result;
        set<int> paint_lookup;

        for (auto& pt : paint)
        {
            int st = pt[0];
            int end = pt[1];

            int count = 0;

            for (int i=st; i<end; i++)
            {
                if (!paint_lookup.count(i))
                {
                    count++;
                }
                paint_lookup.insert(i);
            }

            
            result.push_back(count);
        }
        
        return result;
    }
};