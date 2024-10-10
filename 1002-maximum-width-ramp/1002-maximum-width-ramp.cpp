class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        
        int ans{0};
        int mx = INT_MAX;

        int n = nums.size();

        for(int i{0}; i<n-1; i++)
        {
            if(nums[i]>=mx)
                continue;

            mx = min(mx, nums[i]);
            int j = n-1;

            while(j>i)
            {
                if(nums[i] <= nums[j])
                {
                    ans = max(ans, (j-i));
                    break;
                }
                j--;
            }
        }      

        return ans;     
    }
};