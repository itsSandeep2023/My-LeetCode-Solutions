class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;

        int mn = nums[0], mx = nums[0];

        for(int i{1}; i<n; i++)
        {
            if(mn>nums[i])
                mn = nums[i];
            if(mx<nums[i])
                mx = nums[i];
        }

        int diff = mx - mn - k*2;

        if(diff<=0) return 0;

        return diff;
    }
};