class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> t(n*n+1, false);
        int a{0};
        for(auto& vec: grid)
        {
            for(auto& x: vec)
            {
                if(t[x] == true)
                    a = x;
                t[x] = true;
            }
        }

        int b{0};
        for(int i{1}; i<n*n+1; i++)
        {
            if(!t[i])
            {
                b = i;
                break;
            }
        }

        return {a, b};
    }
};