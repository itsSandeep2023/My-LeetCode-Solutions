class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // ios::sync_with_stdio(false);

        vector<int> sums;
        int mod = 1e9 + 7;

        for (int i{0}; i < n; i++) {
            int csum{0};
            for (int j = i; j < n; j++) {
                csum += nums[j];
                sums.push_back(csum);
            }
        }

        sort(sums.begin(), sums.end());

        int ans{0};

        for (int i = left - 1; i < right; i++) {
            ans = (ans + sums[i]) % mod;
        }

        return ans;
    }
};