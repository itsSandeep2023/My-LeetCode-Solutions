class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        priority_queue<int> sums;
        int mod = 1e9 + 7;

        for (int i{0}; i < n; i++) {
            int csum{0};
            for (int j = i; j < n; j++) {
                csum -= nums[j];
                sums.push(csum);
            }
        }

        int i = 1;
        while (i < left) {
            sums.pop();
            i++;
        }

        int ans{0};
        while (i <= right) {
            ans = (ans - sums.top()) % mod;
            sums.pop();
            i++;
        }

        return ans;
    }
};