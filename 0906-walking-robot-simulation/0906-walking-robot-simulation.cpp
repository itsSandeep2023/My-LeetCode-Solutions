class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;

        for (auto& obs : obstacles) {
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }

        int x{0}, y{0};

        int ans{0};

        pair<int, int> dir = {0, 1};

        for (const auto& com : commands) {
            if (com == -2) {
                dir = {-dir.second, dir.first};
            } else if (com == -1) {
                dir = {dir.second, -dir.first};
            } else {
                for (int i{0}; i < com; i++) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    string nextKey = to_string(newX) + "_" + to_string(newY);

                    if (st.count(nextKey)) {
                        break;
                    }

                    x = newX;
                    y = newY;
                }

                ans = max(ans, (x * x + y * y));
            }
        }

        return ans;
    }
};
