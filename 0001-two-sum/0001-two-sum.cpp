class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;

        for (int i{0}; i < nums.size(); i++) {
            int x = target - nums[i];
            if (s.find(x) != s.end()) {
                return {s[x], i};
            }

            s[nums[i]] = i;
        }

        return {};
    }
};