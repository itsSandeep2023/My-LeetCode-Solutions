class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans{0};
        int mx{0};
        for (int i{0}, n = arr.size(); i < n; i++) {
            mx = max(mx, arr[i]);
            ans += (mx==i);
        }

        return ans;
    }
};