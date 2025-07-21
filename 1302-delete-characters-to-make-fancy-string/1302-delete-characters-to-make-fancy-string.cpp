class Solution {
public:
    string makeFancyString(string s) {
        ios::sync_with_stdio(false);
        
        if(s.size()<=2) return s;
        string ans;
        ans += s[0];
        ans += s[1];

        for(int i{2}; i<s.size(); i++)
        {
            if(s[i] == ans.back() and s[i] == ans[ans.size()-2])
                continue;

            ans.push_back(s[i]);
        }

        return ans;
    }
};