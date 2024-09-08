class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int mx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans += mx;
            mx = max(mx, nums[i]);
        }
        return ans;
    }
};