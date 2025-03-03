class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans(n + 1);

        for (int i{0}; i < n; i++) {
            for (int j{0}; j < n; j++) {
                ans[matrix[i][j]]++;
                if (ans[matrix[i][j]] > i + 1)
                    return false;
            }
        }

        for (int j{0}; j < n; j++) {
            for (int i{0}; i < n; i++) {
                ans[matrix[i][j]]++;
                if (ans[matrix[i][j]] > n + j + 1)
                    return false;
            }
        }

        return true;
    }
};