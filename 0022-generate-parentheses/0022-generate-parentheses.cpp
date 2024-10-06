class Solution {
public:
    void go(vector<string> &ans, string &cur, int &l, int &r, int &n)
    {
        if(cur.size() == n*2)
        {
            ans.push_back(cur);
            return;
        }

        if(l<n)
        {
            l++;
            cur.push_back('(');
            go(ans, cur, l, r, n);
            cur.pop_back();
            l--;
        }

        if(r<l)
        {
            r++;
            cur.push_back(')');
            go(ans, cur, l, r, n);
            cur.pop_back();
            r--;
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        int l{0}, r{0};

        go(ans, cur, l, r, n);

        return ans;
    }
};