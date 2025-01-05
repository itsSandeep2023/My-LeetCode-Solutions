class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        int sum{0};
        string ans(n, ' ');

        for (int i{n - 1}; i >= 0; i--) {
            sum = (sum + shifts[i]) % 26;
            int csf = (sum + s[i] - 'a') % 26;
            ans[i] = csf + 'a';
        }

        return ans;
    }
};