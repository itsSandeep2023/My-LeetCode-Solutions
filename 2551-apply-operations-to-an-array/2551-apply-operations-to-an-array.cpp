class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        int i{0};
        for (; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
                i++;
            }
        }

        i = 0;

        while (i < n and nums[i] != 0)
            i++;

        int j = i;

        while (j < n) {

            while (j < n and nums[j] == 0)
                j++;
            if (j < n)
                swap(nums[i], nums[j]);
            i++;
        }
        
        return nums;
    }
};