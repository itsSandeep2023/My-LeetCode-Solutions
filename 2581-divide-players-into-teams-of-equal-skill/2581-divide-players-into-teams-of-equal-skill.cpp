class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int, int> mp;

        int sm = INT_MAX;
        int mx = 0;

        for (const auto& x : skill) {
            mp[x]++;
            sm = min(sm, x);
            mx = max(mx, x);
        }

        long long ans{0};
        int target = sm + mx;

        for (const auto& x : skill) {
            int t = abs(target - x);

            if (mp[t] > 0) {
                ans += x * t;
                mp[t]--;
            } else {
                return -1;
            }
        }

        ans /= 2;
        return ans;
    }
};