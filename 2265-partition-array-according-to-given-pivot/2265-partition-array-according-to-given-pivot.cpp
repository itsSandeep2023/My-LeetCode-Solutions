class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        ios::sync_with_stdio(0);
        
        int n = nums.size();
        vector<int> ans(n);
        int i{0};
        int ps{0};

        for (auto& x : nums) {
            if (x == pivot)
                ps++;
            else if (x < pivot)
                ans[i++] = x;
        }

        while (ps--)
            ans[i++] = pivot;

        for (auto& x : nums)
            if (x > pivot)
                ans[i++] = x;

        return ans;
    }
};