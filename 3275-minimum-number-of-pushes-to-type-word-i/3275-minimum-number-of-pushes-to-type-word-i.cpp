class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, int> mp;

        int ans{0};

        int n{2};

        for (const auto& ch : word) {
            if (n > 9) {
                n = 2;
            }

            mp[n]++;

            ans += mp[n];

            n++;
        }

        return ans;
    }
};