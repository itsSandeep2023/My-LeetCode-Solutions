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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childSet;

        for (const auto& v : descriptions) {
            int parent = v[0];
            int child = v[1];
            int isLeft = v[2];

            if (!mp.count(parent)) {
                mp[parent] = new TreeNode(parent);
            }

            if (!mp.count(child)) {
                mp[child] = new TreeNode(child);
            }

            if (isLeft) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            childSet.insert(child);
        }

        for (const auto& v : descriptions) {
            if (!childSet.count(v[0])) {
                return mp[v[0]];
            }
        }

        return NULL;
    }
};