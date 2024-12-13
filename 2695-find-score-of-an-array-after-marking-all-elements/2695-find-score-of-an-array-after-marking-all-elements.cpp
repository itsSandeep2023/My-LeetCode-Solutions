class Solution {
public:
    long long findScore(vector<int>& nums) {
        ios::sync_with_stdio(false);
        
        long long ans = 0;
        for (int i = 0, n = nums.size(); i < n; i += 2) {
            int i0 = i;
            while (i + 1 < n && nums[i] > nums[i + 1])
                ++i;
            for (int j = i; j >= i0; j -= 2)
                ans += nums[j];
        }
        return ans;
    }
};