class Solution {
public:
    struct TrieNode {
        TrieNode* childrens[26];
        TrieNode() {
            for (int i{0}; i < 26; i++)
                childrens[i] = NULL;
        }
    };

    class Trie {
        TrieNode* root;

    public:
        Trie() { root = new TrieNode(); }

        void insert(string& word) {
            TrieNode* temp = root;

            for (auto& ch : word) {
                int child = ch - 'a';
                if (!temp->childrens[child])
                    temp->childrens[child] = new TrieNode();
                temp = temp->childrens[child];
            }
        }

        int find(int idx, string& t, vector<int>& dp) {
            if (idx == t.size())
                return 0;
            TrieNode* temp = root;
            if (dp[idx] != -1)
                return dp[idx];
            int ans = 1e4;
            int i = idx;
            int n = t.size();
            while (i < n) {
                int child = t[i] - 'a';
                if (!temp->childrens[child])
                    break;
                ans = min(ans, (find(i + 1, t, dp) + 1));
                temp = temp->childrens[child];
                i++;
            }
            return dp[idx] = ans;
        }
    };

    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        Trie t;
        vector<int> dp(n, -1);

        for (auto word : words)
            t.insert(word);
        int ans = t.find(0, target, dp);
        if (ans >= 1e4)
            return -1;

        return ans;
    }
};