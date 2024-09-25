class Solution {

    class Trie;

    class Node {
        int cnt;
        Node* childrens[26];

    public:
        Node() {
            for (int i{0}; i < 26; i++) {
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

        void insert(string word) {
            int n = word.size();
            Node* t = root;
            int i{0};
            while (i < n) {
                if (!t->childrens[word[i] - 'a'])
                    t->childrens[word[i] - 'a'] = new Node();

                t = t->childrens[word[i] - 'a'];
                t->cnt++;
                i++;
            }
        }

        int find(string& word) {
            int n = word.size();
            Node* t = root;
            int i{0};
            int cnt{0};
            while (i < n) {
                if (t->childrens[word[i] - 'a'] == NULL)
                    break;
                t = t->childrens[word[i] - 'a'];
                cnt += t->cnt;
                i++;
            }

            return cnt;
        }
    };

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        ios::sync_with_stdio(false);
        
        Trie t;

        for (auto& x : words)
            t.insert(x);

        vector<int> ans;

        for (auto& x : words)
            ans.push_back(t.find(x));

        return ans;
    }
};