class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans{0};
        int a{0}, b{0};

        int i{0}, j{0};

        while (j < s.size()) {
            if (s[j++] == '1')
                a++;
            else
                b++;

            while (a > k and b > k) {
                if (s[i++] == '1')
                    a--;
                else
                    b--;
            }

            ans += j - i;
        }

        return ans;
    }
};