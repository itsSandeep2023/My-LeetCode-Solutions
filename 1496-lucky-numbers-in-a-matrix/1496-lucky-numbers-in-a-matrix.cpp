class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> row(n, vector<int>(2, INT_MAX));
        vector<int> col(m, -1);

        for(int i{0};i<n;i++)
        {
            for(int j{0};j<m;j++)
            {
                if(row[i][0] > matrix[i][j])
                {
                    row[i][0] = matrix[i][j];
                    row[i][1] = j;
                }
                col[j] = max(col[j], matrix[i][j]);
            }
        }

        for(int i{0};i<n;i++)
        {
            if(row[i][0] == col[row[i][1]])
            {
                ans.push_back(row[i][0]);
            }
        }

        return ans;
    }
};