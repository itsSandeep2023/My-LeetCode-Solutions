class Solution {
public:
    void go(vector<string>& ans, string s, int& n) {
        if (s.size() >= n) {
            if (s.size() > n)
                s.pop_back();
            ans.push_back(s);
            return;
        }

        go(ans, s + "01", n);
        go(ans, s + "1", n);
    }

    vector<string> validStrings(int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector<string> ans;
        go(ans, "", n);
        return ans;
    }
};