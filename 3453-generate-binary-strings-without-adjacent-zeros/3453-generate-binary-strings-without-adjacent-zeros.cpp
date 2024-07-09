class Solution {
public:
    void go(vector<string>& ans, string s, int& n) {
        if (s.size() >= n) {
            if(s.size()>n)
                s.pop_back();
            ans.push_back(s);
            return;
        }
        
        go(ans, s + "01", n);
        go(ans, s + "1", n);
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string s;
        go(ans, s, n);
        return ans;
    }
};