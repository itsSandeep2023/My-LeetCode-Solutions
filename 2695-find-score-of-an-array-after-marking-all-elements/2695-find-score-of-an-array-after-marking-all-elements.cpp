class Solution {
public:
    long long findScore(vector<int>& nums) {
        ios::sync_with_stdio(false);
        
        int n = nums.size();

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (nums[a] == nums[b])
                return a < b;
            return nums[a] < nums[b];
        });

        vector<bool> marked(n, false);

        long long score{0};
        for (auto& x : idx) {
            if (!marked[x]) {
                score += nums[x];
                if (x > 0)
                    marked[x - 1] = true;
                if (x < n - 1)
                    marked[x + 1] = true;
            }
        }

        return score;
    }
};