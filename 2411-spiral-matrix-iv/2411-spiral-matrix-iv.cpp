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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int left = {0};
        int right = n - 1;
        int top = {0};
        int down = m - 1;

        while (head) {
            int i = left;

            // left to right
            while (head and i <= right) {
                ans[top][i++] = head->val;
                head = head->next;
            }

            i = ++top;

            // top to down
            while (head and i<=down)
            {
                ans[i++][right] = head->val;
                head = head->next;
            }

            i = --right;

            // right to left
            while(head and i>=left)
            {
                ans[down][i--] = head->val;
                head = head->next;
            }

            i = --down;

            // down to top
            while(head and i>=top)
            {
                ans[i--][left] = head->val;
                head = head->next;
            }
            
            i = ++left;
        }

        return ans;
    }
};