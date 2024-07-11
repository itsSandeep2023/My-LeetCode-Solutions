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
    int totalsum{0};

    bool hasPathSum(TreeNode* root, int& targetSum) {
        if (!root)
            return false;

        totalsum += root->val;

        if (totalsum == targetSum and !root->left and !root->right) {
            return true;
        }

        bool result = hasPathSum(root->left, targetSum) or
                      hasPathSum(root->right, targetSum);

        totalsum -= root->val;
        return result;
    }
};