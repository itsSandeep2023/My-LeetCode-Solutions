class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int target{0};

        for (const auto& x : nums)
            target = (target + x) % p;

        if (target == 0)
            return 0;

        unordered_map<int, int> mp;

        int ans = n;
        mp[0] = -1;
        int cur{0};

        for (int i{0}; i < n; i++) {
            cur = (cur + nums[i]) % p;

            int prev = (cur - target + p) % p;
            if (mp.count(prev))
                ans = min(ans, (i - mp[prev]));

            mp[cur] = i;
        }

        return ans == n ? -1 : ans;
    }
};