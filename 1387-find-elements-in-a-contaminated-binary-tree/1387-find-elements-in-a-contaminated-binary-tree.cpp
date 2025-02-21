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
class FindElements {
    unordered_set<int> st;
public:
    FindElements(TreeNode* root) {
        if(root) root->val = 0;
        help(root);
    }

    void help(TreeNode* r)
    {
        st.insert(r->val);
        if(r->left)
        {
            r->left->val = r->val * 2 + 1;
            help(r->left);
        }

        if(r->right)
        {
            r->right->val = r->val * 2 + 2;
            help(r->right);
        }
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */