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
    int minimumOperations(TreeNode* root) {
        int ans{0};
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            
            vector<int> arr;
            while(size--)
            {
                TreeNode* t = q.front();
                q.pop();
                arr.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }

            for(int i{0}, n = arr.size(); i<n; i++)
            {
                int mn = i;
                for(int j{i+1}; j<n; j++)
                {
                    if(arr[mn]> arr[j])
                        mn = j;
                }

                if(mn!=i)
                {
                    ans++;
                    swap(arr[mn], arr[i]);
                }
            }
        }

        return ans;
    }
};