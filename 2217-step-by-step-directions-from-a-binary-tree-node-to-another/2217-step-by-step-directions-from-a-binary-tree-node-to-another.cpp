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
    TreeNode* lowestCommonAncestor(TreeNode* root, int& src, int& dest) {
        if (!root)
            return NULL;

        if (root->val == src or root->val == dest) {
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root->left, src, dest);
        TreeNode* r = lowestCommonAncestor(root->right, src, dest);

        if (l and r)
            return root;

        return l ? l : r;
    }

    bool findPath(TreeNode* root, int& target, string& path)
    {
        if(!root) return false;

        if(root->val==target) return true;

        path.push_back('L');
        if(findPath(root->left, target, path))
        {
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findPath(root->right, target, path))
        {
            return true;
        }
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);

        string lca2src;
        string lca2dest;

        findPath(LCA, startValue, lca2src);
        findPath(LCA, destValue, lca2dest);

        string ans;

        for (const auto& ch : lca2src)
            ans.push_back('U');

        ans += lca2dest;

        return ans;
    }
};