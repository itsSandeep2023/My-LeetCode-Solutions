class Solution {
public:
    int binarySearch(vector<int>& nums, int& k, int i) {
        int l = i + 1;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] - k * 2 <= nums[i]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return l - i;
    }

    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans{1};

        for (int i{0}; i < n; i++) {
            ans = max(ans, binarySearch(nums, k, i));
        }

        return ans;
    }
};