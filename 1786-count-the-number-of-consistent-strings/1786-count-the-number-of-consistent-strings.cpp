class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios::sync_with_stdio(false);

        int ans{0};
        int mask = 0;

        for (auto& ch : allowed)
            mask |= (1 << (ch - 'a'));

        for (auto& word : words) {
            bool allow = true;
            for (auto& ch : word) {
                if (!(mask & (1 << (ch - 'a'))))
                    allow = false;
            }

            if (allow)
                ans++;
        }

        return ans;
    }
};