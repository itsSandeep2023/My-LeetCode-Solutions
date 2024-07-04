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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* p = l1;
        ListNode* n = l1->next;

        int s = p->val + l2->val;
        
        p->val = s % 10;
        l2 = l2->next;

        int c = s / 10;

        while (l2 or c) {
            s = c;

            if (l2) {
                s += l2->val;
                l2 = l2->next;
            }

            if (!n) {
                n = new ListNode(0);
                p->next = n;
            }

            s += n->val;

            n->val = s % 10;
            p = n;
            n = n->next;

            c = s / 10;
        }

        return l1;
    }
};