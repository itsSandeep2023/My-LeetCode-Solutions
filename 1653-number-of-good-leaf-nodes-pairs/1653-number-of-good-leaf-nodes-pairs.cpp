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

    void getGraph(TreeNode* root, unordered_map<TreeNode*, vector<TreeNode*>>& adj, unordered_set<TreeNode*>& st)
    {
        if(!root->left and !root->right)
        {
            st.insert(root);
            return;
        }

        if(root->left)
        {
            adj[root].push_back(root->left);
            adj[root->left].push_back(root);
            getGraph(root->left, adj, st);
        }

        if(root->right)
        {
            adj[root].push_back(root->right);
            adj[root->right].push_back(root);
            getGraph(root->right, adj, st);
        }
    }

    int countPairs(TreeNode* root, int distance) {
        ios::sync_with_stdio(false);
        
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;

        if(root)
        {
            getGraph(root, adj, st);
        }

        int ans{0};

        for(auto& leaf: st)
        {
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(leaf);
            visited.insert(leaf);

            for(int i = 0; i<= distance; i++)
            {
                int size = q.size();
                while(size--)
                {
                    TreeNode* curr = q.front();
                    q.pop();

                    if(curr!=leaf and st.count(curr))
                    {
                        ans++;
                    }

                    for(auto& nbr : adj[curr])
                    {
                        if(!visited.count(nbr))
                        {
                            q.push(nbr);
                            visited.insert(nbr);
                        }
                    }
                }
            }
        }

        return ans/2;
    }
};