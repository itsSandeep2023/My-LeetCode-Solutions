class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26, 0);

        for (const auto& ch : word)
            v[ch - 'a']++;

        sort(v.begin(), v.end(), greater<int>());

        int ans{0};

        for (int i{0}; i < v.size(); i++) {
            if (v[i] == 0)
                break;
            ans += v[i] * ((i / 8) + 1);
        }

        return ans;
    }
};