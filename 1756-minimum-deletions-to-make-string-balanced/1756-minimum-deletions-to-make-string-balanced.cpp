class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int ans{0};

        for(const auto& ch : s)
        {
            if(!st.empty() and st.top() == 'b' and ch == 'a')
            {
                ans++;
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }

        return ans;
    }
};