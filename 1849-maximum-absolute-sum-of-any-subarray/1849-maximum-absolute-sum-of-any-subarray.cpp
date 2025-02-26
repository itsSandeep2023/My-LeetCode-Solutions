class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx{0}, mn{0};
        int cmx{0}, cmn{0};

        for(int i{0}, n = nums.size(); i<n; i++)
        {
            cmx+=nums[i];
            cmn+=nums[i];

            if(cmx<0)
                cmx = 0;
            if(cmn>0)
                cmn=0;
            
            mx = max(mx, cmx);
            mn = min(mn, cmn);
        }

        mn *= -1;

        return max(mx, mn);
    }
};