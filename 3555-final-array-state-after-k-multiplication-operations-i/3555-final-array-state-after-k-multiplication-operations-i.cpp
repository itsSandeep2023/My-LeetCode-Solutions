class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int j{0};

        while(k--)
        {
            j=0;
            for(int i{0};i<nums.size();i++)
            {
                if(nums[i]<nums[j])
                    j = i;
            }
            nums[j] *= multiplier;
        }

        return nums;
    }
};