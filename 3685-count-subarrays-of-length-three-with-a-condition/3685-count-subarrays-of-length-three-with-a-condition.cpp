class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans{0};
        int sum = nums[0] + nums[1] + nums[2];
        if ((sum*2 == nums[1]*3))
            ans++;
        cout<<sum;
        for (int i{3}, n = nums.size(); i < n; i++) {
            sum += nums[i] - nums[i - 3];
            if (sum*2 == (nums[i-1] * 3))
                ans++;
        }

        return ans;
    }
};