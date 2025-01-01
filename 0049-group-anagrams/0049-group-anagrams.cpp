class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto & str: strs)
        {
            auto x = str;
            sort(x.begin(), x.end());
            mp[x].push_back(str);
        }
        vector<vector<string>> result(mp.size());

        int index = 0;
        for(auto & items: mp)
        {
            result[index++] = std::move(items.second);
        }
        return result;
    }
};