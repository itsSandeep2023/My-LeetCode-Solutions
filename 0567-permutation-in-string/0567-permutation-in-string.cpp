class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios::sync_with_stdio(false);
        
        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        vector<int> freq(26, 0);

        for (const auto& x : s1)
            freq[x - 'a']++;

        vector<int> cur(26, 0);

        for (int i{0}; i < n - 1; i++) {
            cur[s2[i] - 'a']++;
        }

        for (int i{0}; i <= (m - n); i++) {
            cur[s2[i + n - 1] - 'a']++;
            bool yes = true;
            for (int j{0}; j < 26; j++) {
                if (freq[j] != cur[j]) {
                    yes = false;
                    break;
                }
            }

            if (yes)
                return true;

            cur[s2[i] - 'a']--;
        }

        return false;
    }
};