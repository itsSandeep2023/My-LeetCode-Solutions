class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int imin = arrays[0].front();
        int imax = arrays[0].back();

        int ans{0};

        for (int i{1}; i < arrays.size(); i++) {
            int cmin = arrays[i].front();
            int cmax = arrays[i].back();

            ans = max(ans, max(abs(imin - cmax), abs(imax - cmin)));

            imin = min(imin, cmin);
            imax = max(imax, cmax);
        }

        return ans;
    }
};