class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans{0};
        int sum{0};
        for (int i{0}, n = arr.size(); i < n; i++) {
            sum+=arr[i] - i;
            ans+=(sum==0);
        }

        return ans;
    }
};