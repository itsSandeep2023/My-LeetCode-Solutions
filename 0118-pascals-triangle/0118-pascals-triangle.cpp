class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i{0}; i<numRows; i++){
            vector<int> t;
            t.push_back(1);

            int n = ans.size();

            for(int j{0};j<i-1;j++)
            {
                t.push_back(ans[n-1][j] + ans[n-1][j+1]);
            }

            if(i!=0)
            {
                t.push_back(1);
            }

            ans.push_back(t);
        }

        return ans;
    }
};