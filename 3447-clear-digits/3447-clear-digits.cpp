class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        bool rem[100] = {false};
        stack<int> st;

        for(int i{0}; i<n; i++)
        {
            if(s[i]-'0'<10)
            {
                if(!st.empty())
                {
                    rem[i] = rem[st.top()] = true;
                    st.pop();
                }
            }
            else
            {
                st.push(i);
            }
        }

        string ans;
        for(int i{0}; i<n; i++)
        {
            if(!rem[i])
                ans.push_back(s[i]);
        }

        return ans;
    }
};