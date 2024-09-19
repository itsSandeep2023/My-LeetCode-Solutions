class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = b.size();

        vector<long long> dp0(n + 1, LLONG_MIN);
        vector<long long> dp1(n + 1, LLONG_MIN);
        vector<long long> dp2(n + 1, LLONG_MIN);
        vector<long long> dp3(n + 1, LLONG_MIN);

        for (int i = n - 1; i >= 3; i--) {
            long long x = (long long)(b[i]) * a[3];
            dp3[i] = max(dp3[i + 1], x);
        }

        for (int i = n - 2; i >= 2; i--) {
            long long x = (long long)(b[i]) * a[2];
            dp2[i] = max(dp2[i + 1], x + dp3[i + 1]);
        }

        for (int i = n - 3; i >= 1; i--) {
            long long x = (long long)(b[i]) * a[1];
            dp1[i] = max(dp1[i + 1], x + dp2[i + 1]);
        }

        for (int i = n - 4; i >= 0; i--) {
            long long x = (long long)(b[i]) * a[0];
            dp0[i] = max(dp0[i + 1], x + dp1[i + 1]);
        }

        return dp0[0];
    }
};