class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans{0};

        unordered_set<char> st;
        for (int i{0}, n = s.size(); i < n - 2; i++) {
            if (!st.count(s[i])) {
                for (int j{n - 1}; j >= i + 2; j--) {
                    if (s[i] == s[j]) {
                        unordered_set<char> t;
                        for (int k{i + 1}; k < j; k++) {
                            if (!t.count(s[k])) {
                                ans++;
                                t.insert(s[k]);
                            }
                        }

                        break;
                    }
                }

                st.insert(s[i]);
            }
        }

        return ans;
    }
};