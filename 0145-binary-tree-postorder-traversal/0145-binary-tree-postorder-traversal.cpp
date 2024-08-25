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
public:
    void pot(TreeNode* r, vector<int>& ans) {
        if (!r)
            return;

        pot(r->left, ans);
        pot(r->right, ans);

        ans.push_back(r->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        ios::sync_with_stdio(false);

        vector<int> ans;
        pot(root, ans);
        return ans;
    }
};