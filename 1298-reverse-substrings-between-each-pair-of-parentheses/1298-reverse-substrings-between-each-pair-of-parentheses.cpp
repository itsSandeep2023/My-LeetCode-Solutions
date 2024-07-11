class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans;
        for (const auto& ch : s) {
            if (ch == '(')
                st.push(ans.length());
            else if (ch == ')') {
                int i = st.top();
                st.pop();
                reverse(ans.begin() + i, ans.end());
            } else
                ans.push_back(ch);
        }

        return ans;
    }
};