class Solution {
public:

    int GCD(int a, int b)
    {
        if(b==0) return a;
        return GCD(b, a%b);
    }

    int findGCD(vector<int>& nums) {
        ios::sync_with_stdio(false);
        
        int sm = nums[0];
        int lg = nums[0];

        for(const auto& x : nums){
            sm = min(sm, x);
            lg = max(lg, x);
        }

        return GCD(sm, lg);
    }
};