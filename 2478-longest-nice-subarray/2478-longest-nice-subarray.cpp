class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int j{0};
        int OR{0};

        int lns{1};

        for(int i{0}; i<n; i++)
        {
            while(OR & nums[i])
            {
                OR &= ~nums[j++];
            }
            
            OR |= nums[i];

            if(lns < i-j+1)
                lns = i-j+1;
        }

        return lns;
    }
};