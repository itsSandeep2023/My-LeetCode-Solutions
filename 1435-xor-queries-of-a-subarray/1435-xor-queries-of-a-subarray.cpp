class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios::sync_with_stdio(false);

        vector<int> cmlxor;
        cmlxor.push_back(arr[0]);

        for (int i{1}; i < arr.size(); i++)
            cmlxor.push_back(cmlxor.back() ^ arr[i]);

        vector<int> ans;
        for (auto& q : queries)
            ans.push_back(cmlxor[q[1]] ^ (q[0] == 0 ? 0 : cmlxor[q[0] - 1]));

        return ans;
    }
};