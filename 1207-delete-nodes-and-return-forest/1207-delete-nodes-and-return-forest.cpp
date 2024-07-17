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
    TreeNode* go(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& ans) {
        if(!root) return NULL;
        
        root->left = go(root->left, st, ans);
        root->right = go(root->right, st, ans);

        if(!st.count(root->val))
            return root;
        
        if(root->left)
            ans.push_back(root->left);
        if(root->right)
            ans.push_back(root->right);
        
        return NULL;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;

        for (const auto& x : to_delete) {
            st.insert(x);
        }

        vector<TreeNode*> ans;

        if(!st.count(root->val))
            ans.push_back(root);

        go(root, st, ans);

        return ans;
    }
};