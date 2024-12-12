class Solution {
private:
    int dfs(TreeNode* node) {
        if (node == nullptr)
            return 0;

        int leftdfs = dfs(node->left);
        if (leftdfs == -1)
            return -1;

        int rightdfs = dfs(node->right);
        if (rightdfs == -1)
            return -1;

        if (abs(leftdfs - rightdfs) > 1)
            return -1;

        return max(leftdfs, rightdfs) + 1;
    }

public:
    bool isBalanced(TreeNode* root) { return dfs(root) != -1; }
};