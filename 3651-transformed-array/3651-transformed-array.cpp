class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        
        int n = nums.size();
        vector<int> ans(n);
        for(int i{0}; i<n; i++)
        {
            int idx = abs(nums[i])%n;
            if(nums[i]>0)
                idx = (idx + n + i)%n;
            else
                idx = (-idx + n + i)%n;

            ans[i] = nums[idx];
        }

        return ans;
    }
};