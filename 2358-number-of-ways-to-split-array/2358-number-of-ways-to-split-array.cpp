class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long rightsum{0};
        for (auto& x : nums)
            rightsum += x;

        int ans{0};
        long cursum{0};
        for (int i{0}; i < n - 1; i++) {
            rightsum -= nums[i];
            cursum += nums[i];
            if(cursum >= rightsum)
                ans++;
        }

        return ans;
    }
};