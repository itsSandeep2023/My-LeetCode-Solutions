class Solution {
    class Trie;
    
    class Node {
        Node* childrens[10];
    public:
        Node() {
            for (int i{0}; i < 10; i++) {
                childrens[i] = NULL;
            }
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
                if (!t->childrens[word[i] - '0'])
                    t->childrens[word[i] - '0'] = new Node();

                t = t->childrens[word[i] - '0'];
                i++;
            }
            cout << endl;
        }

        int find(string& word) {
            int n = word.size();
            Node* t = root;
            int i{0};
            int cnt{0};
            while (i < n) {
                if (t->childrens[word[i] - '0'] == NULL)
                    break;
                t = t->childrens[word[i] - '0'];
                i++;
                cnt++;
            }

            return cnt;
        }
    };

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;

        for (const auto& x : arr1) {
            string word = to_string(x);
            t.insert(word);
        }

        int ans{0};
        for (const auto& x : arr2) {
            string word = to_string(x);
            ans = max(ans, t.find(word));
        }

        return ans;
    }
};
