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
        ios::sync_with_stdio(false);

        string r2src;
        string r2dest;

        findPath(root, startValue, r2src);
        findPath(root, destValue, r2dest);


        int i{0};
        while(i<r2src.size() and i<r2dest.size() and r2src[i]==r2dest[i])
            i++;

        string ans;

        for(int j{0}; j<r2src.size() - i;j++)
        {
            ans.push_back('U');
        }

        ans += r2dest.substr(i, (r2dest.size()-i+1));

        // for(i;i<r2dest.size();i++)
        // {
        //     ans.push_back()
        // }

        return ans;
    }
};