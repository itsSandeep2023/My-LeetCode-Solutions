/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool go(ListNode* head, TreeNode* root) {
        if (!head)
            return true;

        if (!root)
            return false;

        if (head->val == root->val)
            return go(head->next, root->left) or go(head->next, root->right);
        return false;
    }

    bool check(ListNode* head, TreeNode* root) {
        if (!root)
            return false;
        return go(head, root) or isSubPath(head, root->left) or
               isSubPath(head, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        ios::sync_with_stdio(false);
        return check(head, root);
    }
};