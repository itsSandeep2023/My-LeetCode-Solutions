class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (int i{0}; i < n - 1; i++) {
            for (int j{i + 1}; j < n; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }

        int ans{0};

        for (auto& x : mp) {
            if (x.second > 1) {
                ans += (x.second * (x.second - 1)) / 2;
            }
        }

        return ans * 8;
    }
};