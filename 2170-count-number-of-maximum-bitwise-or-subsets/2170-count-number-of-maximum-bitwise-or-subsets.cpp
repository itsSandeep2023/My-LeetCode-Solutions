class Solution {
public:
    int cntSubSets(int i, int curOr, vector<int>& nums, int& maxOr, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            if (curOr == maxOr) {
                return 1;
            }
            return 0;
        }

        if(dp[i][curOr]!=-1)
        {
            cout<<"yes";
            return dp[i][curOr];
        } 

        // inc
        int takeCnt = cntSubSets(i + 1, curOr | nums[i], nums, maxOr, dp);

        // exc
        int excCnt = cntSubSets(i + 1, curOr, nums, maxOr, dp);

        return dp[i][curOr] = (takeCnt + excCnt);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        ios::sync_with_stdio(false);
        
        int maxOr{0};

        for (const auto& x : nums) {
            maxOr |= x;
        }

        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(maxOr+1, -1));

        return cntSubSets(0, 0, nums, maxOr, dp);
    }
};