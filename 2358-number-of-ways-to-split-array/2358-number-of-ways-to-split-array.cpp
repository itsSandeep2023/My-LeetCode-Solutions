class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long> prefsum(n);
        prefsum[0] += nums[0];
        for (int i{1}; i < n; i++)
            prefsum[i] += prefsum[i - 1] + nums[i];

        int ans{0};
        for (int i{0}; i < n - 1; i++) {
            if (prefsum[i] * 2 >= prefsum[n - 1])
                ans++;
        }

        return ans;
    }
};