class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // just k size sum arr and note there can be only n-k+1 arrs are possible 
        vector<int> prefsum(n - k + 1);

        // first k sum
        prefsum[0] = accumulate(nums.begin(), nums.begin() + k, 0);

        for (int i{0}; i < n - k; i++) {
            prefsum[i + 1] = prefsum[i] - nums[i] + nums[i + k];
        }

        // maxsum idx for left 1st sub arr
        vector<int> mx1(n - k + 1);
        // starts from idx 0
        mx1[0] = 0;
        for (int i{1}; i < n - k; i++) {
            // note > because need smallest idx for left to right traverse
            mx1[i] = prefsum[i] > prefsum[mx1[i - 1]] ? i : mx1[i - 1];
        }

        // maxsum idx for right 3rd sub arr
        vector<int> mx3(n - k + 1);
        // starts from idx n - k
        mx3[n - k] = n - k;
        for (int i{n - k - 1}; i >= 0; i--) {
            // note >= because need smallest idx for right to left traverse
            mx3[i] = prefsum[i] >= prefsum[mx3[i + 1]] ? i : mx3[i + 1];
        }

        // need tree idx let a, b, c
        int a, b, c;
        int maxsum{0};
        for (int i{k}; i <= n - k * 2; i++) {
            int csum = prefsum[mx1[i - k]] + prefsum[i] + prefsum[mx3[i + k]];
            // store idxs only if csum > prev maxsum
            if (csum > maxsum) {
                // update values;
                maxsum = csum;
                a = mx1[i - k];
                b = i;
                c = mx3[i + k];
            }
        }

        // return idx as vector
        return {a, b, c};
    }
};