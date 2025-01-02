class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        vector<int> prefsum(n);

        for (int i{0}; i < n; i++) {
            if (i > 0)
                prefsum[i] = prefsum[i - 1];

            if (vowels.count(words[i][0]) and
                vowels.count(words[i][words[i].size() - 1])) {
                prefsum[i]++;
            }
        }

        vector<int> ans;

        for (auto& vec : queries) {
            int cur = prefsum[vec[1]];
            if (vec[0] > 0)
                cur -= prefsum[vec[0] - 1];
            ans.push_back(cur);
        }

        return ans;
    }
};