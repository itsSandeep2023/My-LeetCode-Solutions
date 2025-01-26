class Solution {
public:
    void tokS(const string& str, bool t, vector<int>& ids) {
        stringstream ss(str);
        string token;

        while (ss >> token) {
            if (t) {
                token = token.substr(2);
            }
            ids.push_back(stoi(token));
        }
    }

    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        sort(events.begin(), events.end(),
             [](const vector<string>& a, const vector<string>& b) {
                 int timestampA = stoi(a[1]);
                 int timestampB = stoi(b[1]);

                 if (timestampA == timestampB) {
                     return a[0] == "OFFLINE";
                 }
                 return timestampA < timestampB;
             });
        
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;

        int n = events.size();

        vector<bool> off(numberOfUsers, false);

        vector<int> ans(numberOfUsers);

        for (int i{0}; i < n; i++) {
            string mes = events[i][0];
            int ts = stoi(events[i][1]);
            string id = events[i][2];

            while (!q.empty() and q.top().first <= ts) {
                off[q.top().second] = false;
                q.pop();
            }

            vector<int> ids;

            if (mes[0] == 'M') {
                if (id == "ALL") {
                    for (int i{0}; i < numberOfUsers; i++)
                        ans[i]++;
                    continue;
                } else if (id == "HERE") {
                    for (int i{0}; i < numberOfUsers; i++) {
                        if (!off[i])
                            ans[i]++;
                    }
                    continue;
                }
            }

            tokS(id, mes[0] == 'M', ids);

            if (mes[0] == 'O') {
                for (auto& x : ids) {
                    off[x] = true;
                    q.push({ts + 60, x});
                }
            } else {
                for (auto& x : ids) {
                    ans[x]++;
                }
            }
        }

        return ans;
    }
};