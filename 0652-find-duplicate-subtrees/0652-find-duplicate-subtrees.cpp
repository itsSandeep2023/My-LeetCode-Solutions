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

    string getDS(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*> &ans)
    {
        if(!root) return "N";

        string s = to_string(root->val) + ' ' + getDS(root->left, mp, ans) + ' ' + getDS(root->right, mp, ans);

        if(mp[s]==1)
            ans.push_back(root);
        
        mp[s]++;

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        ios::sync_with_stdio(false);
        // cin.tie(nullptr);

        unordered_map<string, int> mp;
        vector<TreeNode*> ans;

        getDS(root, mp, ans);

        return ans;
    }
};