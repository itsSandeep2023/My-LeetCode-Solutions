class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);

        int n = nums.size();
        int maxEl = *max_element(nums.begin(), nums.end());
        vector<int> vec(maxEl + 1, 0);

        for (int i{0}; i < n - 1; i++)
            for (int j{i + 1}; j < n; j++)
                vec[abs(nums[i] - nums[j])]++;

        for (int d{0}; d < maxEl + 1; d++) {
            k -= vec[d];
            if (k <= 0)
                return d;
        }

        return -1;
    }
};