#define PII pair<int, int>
class Compare {
public:
    bool operator()(PII below, PII above)
    {
        if (below.first < above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second > above.second) {
            return true;
        }
 
        return false;
    }
};

class Solution {
public:

    vector<int> topStudents(vector<string>& positive_feedback,
                            vector<string>& negative_feedback,
                            vector<string>& report, vector<int>& student_id,
                            int k) {

        unordered_map<string, bool> PF;
        for (auto S : positive_feedback)
            PF[S] = true;

        unordered_map<string, bool> NF;
        for (auto S : negative_feedback)
            NF[S] = true;

        priority_queue<PII, vector<PII>, Compare> scores;
        int size = report.size();
        for (int j = 0; j < size; j++) {
            stringstream ss(report[j]);
            string s;
            int points = 0;

            while (getline(ss, s, ' ')) {
                if (PF[s])
                    points += 3;

                else if (NF[s])
                    points -= 1;
            }
            scores.push({points, student_id[j]});
        }

        vector<int> res;
        int count = 0;
        while (count < k) {
            res.push_back(scores.top().second);
            scores.pop();
            count++;
        }
        

        return res;
    }
};