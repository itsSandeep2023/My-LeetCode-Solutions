class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;

        int ans{0};

        for (auto& x : nums) {
            if (x < k)
                return -1;
            if (x == k)
                continue;
            if (!st.count(x)) {
                ans++;
                st.insert(x);
            }
        }

        return ans;
    }
};