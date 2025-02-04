class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int sum = nums[0];
        int n = nums.size();
        int i = 1;

        while (i < n) {
            if (nums[i] > nums[i - 1])
                sum += nums[i];
            else
                sum = nums[i];
            ans = max(ans, sum);
            i++;
        }

        return ans;
    }
};