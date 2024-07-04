class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum INT_MIN;
        int cursum{0};

        for (const auto& x : nums) {
            cursum += x;

            if (cursum > maxsum)
                maxsum = cursum;
                
            if (cursum < 0)
                cursum = 0;
        }

        return maxsum;
    }
};