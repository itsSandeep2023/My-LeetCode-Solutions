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
    unordered_map<TreeNode*, int> mp;
public:

    int rob(TreeNode* root) {
        if(root == nullptr) return 0;

        if(mp.count(root)) return mp[root];

        // include
        int inc = root->val;
        if(root->left != nullptr)
        {
            inc += rob(root->left->left);
            inc += rob(root->left->right);
        }
        if(root->right != nullptr)
        {
            inc += rob(root->right->left);
            inc += rob(root->right->right);
        }

        // exclude
        int exc = 0;
        exc += rob(root->left);
        exc += rob(root->right);

        // returning max form both the cases
        return mp[root] = max(inc, exc);
    }
};