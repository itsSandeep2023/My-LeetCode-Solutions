class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        if (n == 1)
            return 1;

        int i{-1};
        int j{0};

        int cnt{0};

        while (j < n) {
            if (i < 0) {
                s[++i] = s[j++];
                continue;
            }

            if (s[j] == 'D' and s[i] == 'C') {
                cnt += 2;
                j++;
                i--;
            } else if (s[j] == 'B' and s[i] == 'A') {
                cnt += 2;
                j++;
                i--;
            } else {
                s[++i] = s[j++];
            }
        }

        return n - cnt;
    }
};