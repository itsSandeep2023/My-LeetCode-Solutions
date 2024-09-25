class Solution {

    class Trie;

    class Node {
        int cnt;
        Node* childrens[26];                    // Use 26 for lowercase English letters

    public:
        Node() {
            for (int i = 0; i < 26; i++) {
                childrens[i] = NULL;
            }
            cnt = 0;
        }

        friend class Trie;
    };

    class Trie {
        Node* root;

    public:
        Trie() { root = new Node(); }

        void insert(const string& word) {
            int n = word.size();
            Node* t = root;
            for (int i = 0; i < n; i++) {
                int index = word[i] - 'a';      // Map character to index 0-25
                if (!t->childrens[index])
                    t->childrens[index] = new Node();

                t = t->childrens[index];
                t->cnt++;
            }
        }

        int find(const string& word) {
            int n = word.size();
            Node* t = root;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int index = word[i] - 'a';      // Map character to index 0-25
                if (!t->childrens[index])
                    break;
                t = t->childrens[index];
                cnt += t->cnt;                  // Add the count of this prefix
            }

            return cnt;
        }
    };

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        ios::sync_with_stdio(false);
        
        Trie t;

        // Insert each word into the Trie
        for (const auto& x : words)
            t.insert(x);

        vector<int> ans;

        // Calculate prefix scores for each word
        for (const auto& x : words)
            ans.push_back(t.find(x));

        return ans;
    }
};
