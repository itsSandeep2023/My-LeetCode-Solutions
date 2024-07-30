class Solution {
public:
    int minimumDeletions(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int n = s.size();
        int ans = 1e5;

        int rcnta{0};

        for (int i{0}; i < n; i++)
            rcnta += (s[i] == 'a');

        int lcntb{0};
        for (int i{0}; i < n; i++) {
            rcnta -= (s[i] == 'a');
            ans = min(ans, rcnta + lcntb);
            lcntb += (s[i]=='b');
        }

        return ans;
    }
};