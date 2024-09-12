class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios::sync_with_stdio(false);
        
        int ans{0};
        unordered_set<char> st;

        for(auto& ch : allowed)
            st.insert(ch);

        for( auto& word : words)
        {
            bool allow = true;
            for( auto& ch: word)
            {
                if(!st.count(ch))
                {
                    allow = false;
                    break;
                }
            }

            if(allow)
                ans++;
        }

        return ans;
    }
};