class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalsum{0};
        int n = nums.size();
        for(int i{1};i<(1<<n);i++)
        {
            int currsum{0};
            for(int j{0};j<n;j++)
            {
                if(i&(1<<j)) currsum^=nums[j]; 
            }
            totalsum += currsum;
        }

        return totalsum;
    }
};