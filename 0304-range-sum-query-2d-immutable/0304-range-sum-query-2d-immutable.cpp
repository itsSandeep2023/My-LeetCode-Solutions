class NumMatrix {
    vector<vector<long long>> matSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        matSum.resize(n+1, vector<long long>(m+1, 0));

        for(int i{0}; i<n; i++)
        {
            long long sum{0};
            for(int j{0}; j<m; j++)
            {
                sum += matrix[i][j];
                matSum[i+1][j+1] =  matSum[i][j+1] + sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return matSum[row2+1][col2+1] - matSum[row2+1][col1] - matSum[row1][col2+1] + matSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */