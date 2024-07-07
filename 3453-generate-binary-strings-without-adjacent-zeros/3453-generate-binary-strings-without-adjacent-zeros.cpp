class Solution {
public:
    void go(vector<string>& ans, string s, int &n)
    {
        if(s.size()>=n)
        {
            ans.push_back(s);
            return;
        }

        if(s.size()>=1 and s[s.size()-1]=='1')
            go(ans, s+"0",n);
        else if(s.size()==0)
            go(ans, s+"0",n);
        

        go(ans, s+"1",n);
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string s;
        go(ans, s, n);
        return ans;
    }
};