class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k, 0);

        for (const auto& x : arr)
            mp[(x % k + k) % k]++;

        if (mp[0] % 2 != 0)
            return false;

        for (int i{1}; i < k; i++) {
            int counterHalf = k - i;
            if (mp[counterHalf] != mp[i])
                return false;
        }

        return true;
    }
};