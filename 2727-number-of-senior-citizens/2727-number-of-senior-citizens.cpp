class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans{0};

        for(const auto& s: details)
        {
            if(s[11]>'6' or ( s[11]=='6' and s[12]>'0'))
                ans++;
        }

        return ans;
    }
};