class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans{0};

        for(const auto& s: logs)
        {
            if(s == "./")
                continue;
            if(s == "../")
            {
                if(ans>0)
                    ans--;
            }
            else
                ans++;
        }
        
        return ans;
    }
};