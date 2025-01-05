class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        long long sum{0};

        for (int i{n - 1}; i >= 0; i--) {
            sum += shifts[i];
            int csf = (sum + s[i] - 'a') % 26;
            s[i] = csf + 'a';
        }

        return s;
    }
};