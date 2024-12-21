class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans{0};

        for (int i{0}, n = nums.size(); i + 2 < n; i++) {
            if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]) {
                ans += 1;
            }
        }

        return ans;
    }
};