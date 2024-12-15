
class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> lcs(n+1, vector<int>(n+1,0));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= i; j--) {
                if (nums[i] != nums[j]) {
                    lcs[i][j] = 0;
                } else {
                    lcs[i][j] = 1 + lcs[i + 1][j + 1];
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n - 2; i++) {
            for (int j = i + 1; j <= n - 1; j++) {
                // [0, i - 1], [i, j - 1], [j, n - 1]
                int len1 = i, len2 = j - i, len3 = n - j;
                bool ok = len1 <= len2 && lcs[0][i] >= len1;
                ok |= (len2 <= len3 && lcs[i][j] >= len2);
                ans += int(ok);
            }
        }
        return ans;
    }
};