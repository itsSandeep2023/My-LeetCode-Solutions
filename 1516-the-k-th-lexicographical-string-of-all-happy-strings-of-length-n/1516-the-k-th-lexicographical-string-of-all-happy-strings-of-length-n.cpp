class Solution {
    int n;
    int k;
    int cnt{0};
public:
    void solve(string &s)
    {
        if(cnt==k) return;

        if(s.size()>=n)
        {
            cnt++;
            return;
        }

        for(auto ch : {'a', 'b','c'})
        {
            if(s.empty() or s.back()!=ch)
            {
                s.push_back(ch);
                solve(s);
                if(cnt==k) return;
                s.pop_back();
            }
        }
    }
    
    string getHappyString(int n, int k) {
        this->n = n;
        this->k = k;
        string s;
        solve(s);
        return s;
    }
};