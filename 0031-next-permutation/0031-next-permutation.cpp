class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -1;

        int n = nums.size();

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }

        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int min = k + 1;

        for (int i{min}; i < nums.size(); i++) {
            if (nums[i] < nums[min] and nums[i]>nums[k]) {
                min = i;
            }
        }

        swap(nums[k], nums[min]);
        sort(nums.begin() + k + 1, nums.end());
    }
};