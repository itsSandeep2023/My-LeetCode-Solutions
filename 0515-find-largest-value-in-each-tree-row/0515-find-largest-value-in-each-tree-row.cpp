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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int largest = q.front()->val;
            while (size--) {
                TreeNode* t = q.front();
                q.pop();

                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);

                largest = max(largest, t->val);
            }

            ans.push_back(largest);
        }

        return ans;
    }
};