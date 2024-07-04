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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* c = head;
        ListNode* t = head->next;

        while (t) {
            if (t->val != 0) {
                c->val += t->val;
            } else {
                c->next = t->next;
                c = c->next;
                t = t->next;
            }
            
            if(t)
                t = t->next;
        }

        return head;
    }
};