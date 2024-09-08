class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int x = nums[0], j = 1, i = 0;

        while (j < n - 1) {
            if (nums[i] < nums[j]) {
                res += x * 1LL * (j - i);
                i = j;
                x = nums[i];
            }
            j++;
        }

        return res + x * 1LL * (n - 1 - i);
    }
};