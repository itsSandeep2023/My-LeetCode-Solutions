class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> st;

        stringstream ss1(s1);
        stringstream ss2(s2);

        string token;

        while(ss1>>token){
            st[token]++;
        }

        vector<string> ans;
        while(ss2>>token)
        {
            if(!st[token])
            {
                ans.push_back(token);
            }
            else{
                st[token]++;
            }

        }

        for(auto& w : st)
        {
            if(w.second == 1)
                ans.push_back(w.first);
        }

        return ans;
    }
};