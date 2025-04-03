class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long mx = 0;
        long long mx_diff = 0;
        long long ans = 0;
        for (long long num : nums) {
            ans = max(ans, mx_diff * num);
            mx_diff = max(mx_diff, mx - num);
            mx = max(mx, num);
        }
        return ans;
    }
};