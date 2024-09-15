class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> mp;

        int mask{0};
        mp[mask] = -1;

        int ans{0};

        for (int i{0}; i < s.size(); i++) {
            if (s[i] == 'a')
                mask = (mask ^ 1);
            else if (s[i] == 'e')
                mask = (mask ^ 2);
            else if (s[i] == 'i')
                mask = (mask ^ 4);
            else if (s[i] == 'o')
                mask = (mask ^ 8);
            else if (s[i] == 'u')
                mask = (mask ^ 16);

            if (mp.count(mask))
                ans = max(ans, i - mp[mask]);
            else
                mp[mask] = i;
        }

        return ans;
    }
};