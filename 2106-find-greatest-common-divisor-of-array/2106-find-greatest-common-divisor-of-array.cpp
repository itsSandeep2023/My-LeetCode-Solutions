class Solution {
public:
    int findGCD(vector<int>& nums) {
        ios::sync_with_stdio(false);
        
        int sm = nums[0];
        int lg = nums[0];

        for(const auto& x : nums){
            sm = min(sm, x);
            lg = max(lg, x);
        }

        int k = (sm/2);

        for(int i{1}; i<=k; i++)
        {
            int c = (sm / i);

            if(sm%c==0 and lg%c==0)
                return c;
        }

        return 1;
    }
};