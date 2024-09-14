class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios::sync_with_stdio(false);
        
        int ans{1};

        int mx = *max_element(nums.begin(), nums.end());
        int cnt{0};
        for(const auto& x :nums)
        {
            if(x == mx)
            {
                cnt++;
                ans = max(ans, cnt);
            }
            else
                cnt = 0;
        }

        return ans;
    }
};