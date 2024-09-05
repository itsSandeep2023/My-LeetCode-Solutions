class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dir1[] = {1, 0, -1, 0};
        int dir2[] = {0, 1, 0, -1};

        unordered_map<int, vector<int>> xmp;
        unordered_map<int, vector<int>> ymp;

        for (const auto& vec : obstacles) {
            xmp[vec[1]].push_back(vec[0]);
            ymp[vec[0]].push_back(vec[1]);
        }

        int x{0}, y{0};

        int cd = 0;

        int ans{0};

        for (const auto& com : commands) {
            if (com == -1)
                cd = (cd + 1) % 4;
            else if (com == -2)
                cd -= (cd == 0) ? -3 : 1;
            else {
                int d, t;

                bool neg = false;
                if (cd == 0) {
                    d = x;
                    t = y;
                } else if (cd == 1) {
                    d = y;
                    t = x;
                } else if (cd == 2) {
                    d = x;
                    t = y;
                    neg = true;
                } else {
                    d = y;
                    t = x;
                    neg = true;
                }

                vector<int>& cmp = (cd == 1 or cd == 3) ? xmp[d] : ymp[d];
                int dif{com};
                for (auto& it : cmp) {
                    if (neg) {
                        if (it < t) {
                            dif = min(dif, abs(t - it) - 1);
                        }
                    } else if (it > t) {
                        dif = min(dif, (it - t - 1));
                    }
                }

                cout << dif << " " << neg << "  ";
                if (cd == 1 or cd == 3) {
                    x += neg ? -(dif) : (dif);
                } else {
                    y += neg ? -dif : dif;
                }
            }

            ans = max(ans, x * x + y * y);
        }

        return ans;
    }
};
