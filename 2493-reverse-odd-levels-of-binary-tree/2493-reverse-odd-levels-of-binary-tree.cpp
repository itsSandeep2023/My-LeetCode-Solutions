/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void rev(TreeNode* l, TreeNode* r, bool odd = true)
    {
        if(!l) return;

        rev(l->left, r->right, !odd);
        rev(l->right, r->left, !odd);

        if(odd) swap(l->val, r->val);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        ios::sync_with_stdio(false);
        rev(root->left, root->right);
        return root;
    }
};