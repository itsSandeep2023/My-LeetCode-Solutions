class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;

        for(const auto& x: arr)
            mp[x]++;

        for(const auto& x: target)
        {
            if(!mp[x])
                return false;
            mp[x]--;
        }

        return true;
    }
};