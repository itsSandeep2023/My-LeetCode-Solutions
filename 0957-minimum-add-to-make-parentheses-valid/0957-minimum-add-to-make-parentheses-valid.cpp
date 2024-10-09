class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans{0};
        int cnt{0};

        for(const auto& x : s)
        {
            if(x == '(')
                cnt++;
            else if(cnt>0)
                cnt--;
            else
                ans++;
        }

        return ans + cnt;
    }
};