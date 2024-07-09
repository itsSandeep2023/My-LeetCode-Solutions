class Solution {
public:
    struct trie {
        trie* next[26];
        int cost;
        trie() {
            cost = INT_MAX;
            for (int i{0}; i < 26; i++)
                next[i] = nullptr;
        }
    };

    void insert(trie* root, string s, int cost) {
        for (auto ch : s) {
            if (!root->next[ch - 'a'])
                root->next[ch - 'a'] = new trie();
            root = root->next[ch - 'a'];
        }
        root->cost = min(cost, root->cost);
    }

    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        trie* root = new trie();
        int n = costs.size();

        vector<long long> dp(target.size() + 1, INT_MAX);
        dp[target.size()] = 0;
        for (int i = 0; i < n; i++) {
            insert(root, words[i], costs[i]);
        }
        for (int i = target.size() - 1; i >= 0; i--) {
            long long ans = INT_MAX;
            trie* temp = root;
            for (int j = i; j < target.size() && temp; j++) {

                temp = temp->next[target[j]-'a'];
                if (temp && temp->cost != INT_MAX) {
                    ans = min(ans, temp->cost + dp[j + 1]);
                }
            }
            dp[i] = ans;
        }

        return dp[0] >= INT_MAX ? -1 : dp[0];
    }
};