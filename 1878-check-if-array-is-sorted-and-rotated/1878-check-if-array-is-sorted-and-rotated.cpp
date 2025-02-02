class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int t{0};
        for (int i{1}; i < n; i++) {
            if(nums[i]<nums[i-1])
            {
                t = i;
                break;
            }
        }

        for(int i{t+1}; i<n; i++)
        {
            if(nums[i] < nums[i-1])
                return false;
        }

        if(t==0)
            return true;

        if(nums[n-1] > nums[0])
            return false;

        for(int i{1}; i<t; i++)
        {
            if(nums[i] < nums[i-1])
                return false;
        }

        return true;
    }
};