class Solution {
public:
    bool isPal(string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }

        return true;
    }

    string longestPalindrome(string s) {

        int n = s.size();

        int start{0};
        int len{0};

        for (int i{0}; i < n; i++) {
            // int j{n-1};
            for (int j{n - 1}; j > i; j--) {
                if (s[i] == s[j] and isPal(s, i, j)) {
                    if (len < j - i + 1) {
                        start = i;
                        len = j - i + 1;
                    }
                    break;
                }
            }
        }

        return (len==0) ? s.substr(0,1) : s.substr(start, len);
    }
};