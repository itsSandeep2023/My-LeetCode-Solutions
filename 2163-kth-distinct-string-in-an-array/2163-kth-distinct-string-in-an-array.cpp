class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        ios::sync_with_stdio(false);
        unordered_map<string, int> mp;

        for (const auto& s : arr) {
            mp[s]++;
        }

        for (const auto& s : arr) {
            if (mp[s] == 1) {
                k--;
                if (k == 0)
                    return s;
            }
        }

        return "";
    }
};