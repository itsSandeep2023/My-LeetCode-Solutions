class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0];
        int cmx = 0;

        for (const auto& x : nums) {
            cmx += x;
            mx = max(mx, cmx);

            if(cmx<0)
                cmx = 0;
        }

        return mx;
    }
};