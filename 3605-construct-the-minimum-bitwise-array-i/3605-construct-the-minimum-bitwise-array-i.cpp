class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            if (x == 2)
            {
                ans.push_back(-1);
                continue;
            }
            int y = (x - (x & (x + 1)) + 1) / 2;
            ans.push_back(x - y);
        }
        return ans;
    }
};