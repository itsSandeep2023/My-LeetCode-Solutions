class Solution {
public:
    long long maximumTotalSum(vector<int>& mxh) {
        // ios::sync_with_stdio(false);

        sort(mxh.begin(), mxh.end());
        int n = mxh.size();

        long long ans = mxh[n-1];
        int cmx = ans;

        for (int i = n - 2; i >= 0 ; i--) {
            cmx = min(mxh[i], cmx-1);

            if(cmx<=0)
                return -1;

            ans+= cmx;
        }

        return ans;
    }
};