class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans{0};
        for (auto& x : nums)
            if (x < k)
                ans++;

        return ans;
    }
};