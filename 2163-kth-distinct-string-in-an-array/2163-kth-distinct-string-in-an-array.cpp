class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        for (const auto& s : arr) {
            mp[s]++;
        }

        for (const auto& s : arr) {
            if (mp[s] == 1) {
                if (k == 1)
                    return s;
                k--;
            }
        }

        return "";
    }
};