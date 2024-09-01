class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        ios::sync_with_stdio(false);

        if (original.size() != m * n)
            return {};

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i{0}; i < original.size(); i++) {
            ans[i / n][i % n] = original[i];
        }

        return ans;
    }
};