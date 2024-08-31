class Solution {
public:
    string stringHash(string s, int k) {
        string ans;

        for (int i{0}; i < s.size();) {
            int t = 0;
            int cnt{0};
            while (t++ < k) {
                cnt += s[i] - 'a';
                i++;
            }
            ans+=cnt%26 + 'a';
        }

        return ans;
    }
};