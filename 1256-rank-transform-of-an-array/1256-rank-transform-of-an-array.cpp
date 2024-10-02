class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st;

        for (const auto& x : arr)
            st.insert(x);

        unordered_map<int, int> mp;

        int i{1};

        for (auto& x : st)
            mp[x] = i++;

        for (auto& x : arr)
            x = mp[x];

        return arr;
    }
};