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
    int ans{0};
public:

    int bst(TreeNode* root, int &low, int &high) {
        if(!root)
            return 0;

        if(root->val >= low and root->val <= high)
            ans += root->val;

        bst(root->left, low, high);
        bst(root->right, low, high);

        return ans;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        bst(root, low, high);

        return ans;
    }
};