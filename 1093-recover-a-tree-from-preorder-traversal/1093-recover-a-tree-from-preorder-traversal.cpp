/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int n;

public:
    TreeNode* solve(string& tr, int& idx, int& level, int& nlevel) {
        if (idx >= n)
            return NULL;

        int cnt{0};
        while (idx < n and tr[idx] != '-') {
            cnt++;
            idx++;
        }

        TreeNode* root = new TreeNode(stoi(tr.substr(idx - cnt, cnt)));
        nlevel = 0;
        while (idx < n and tr[idx] == '-') {
            idx++;
            nlevel++;
        }

        if (level < nlevel) {
            level++;
            root->left = solve(tr, idx, level, nlevel);
            level--;
        }

        if (level < nlevel) {
            level++;
            root->right = solve(tr, idx, level, nlevel);
            level--;
        }

        return root;
    }

    TreeNode* recoverFromPreorder(string tr) {
        this->n = tr.size();
        int idx{0}, level{0}, nlevel{0};
        return solve(tr, idx, level, nlevel);
    }
};