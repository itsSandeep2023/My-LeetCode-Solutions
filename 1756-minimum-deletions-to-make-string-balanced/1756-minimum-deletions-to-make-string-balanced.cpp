class Solution {
public:
    int minimumDeletions(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n = s.size();

        vector<int> lb(n + 1, 0);
        vector<int> ra(n + 1, 0);

        int ans = 1e5;

        for (int i{0}; i < n; i++) {
            lb[i + 1] = lb[i] + (s[i] == 'b');
        }

        for (int i = n - 1; i >= 0; i--) {
            ra[i] = ra[i + 1] + (s[i] == 'a');

            ans = min(ans, ra[i + 1] + lb[i]);
        }

        return ans;
    }
};