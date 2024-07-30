class Solution {
public:
    int minimumDeletions(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n = s.size();

        vector<int> lb(n + 1, 0);

        int ans = 1e5;

        for (int i{0}; i < n; i++) {
            lb[i + 1] = lb[i] + (s[i] == 'b');
        }

        int cnta{0};

        for (int i = n - 1; i >= 0; i--) {
            ans = min(ans, cnta + lb[i]);
            cnta=  cnta + (s[i] == 'a');
        }

        return ans;
    }
};