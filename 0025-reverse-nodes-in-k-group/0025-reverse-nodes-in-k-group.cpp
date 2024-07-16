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
    ListNode* reverseKGroup(ListNode* head, int& k) {
        if (!head or !head->next)
            return head;

        ListNode *p, *c, *n, *t;
        t = head;
        int i = k - 1;
        while (i-- and t)
            t = t->next;

        if(i>0 or !t)
        {
            return head;
        }

        if (t and t->next)
        {
            p = reverseKGroup(t->next, k);
            t->next = NULL;
        }
        else p = NULL;

        
        c = head;
        n = head->next;

        while(c and n)
        {
            // cout<<p->val<<
            c->next = p;
            p=c;
            c=n;
            n=n->next;
        }

        c->next = p;

        return c;
    }
};