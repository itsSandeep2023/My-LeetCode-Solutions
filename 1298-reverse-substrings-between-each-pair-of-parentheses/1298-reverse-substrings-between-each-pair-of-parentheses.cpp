class Solution {
public:
    string reverseParentheses(string s) {
        unordered_map<int, int> mp;
        string ans;
        stack<int> st;
        int n = s.size();

        for (int i{0}; i < n; i++) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                mp[i] = st.top();
                mp[st.top()] = i;
                st.pop();
            }
        }

        int dir = 1;

        for (int i = 0; i < n; i += dir) {
            if (s[i] == '(' or s[i] == ')') {
                i = mp[i];
                dir = -dir;
            } else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};