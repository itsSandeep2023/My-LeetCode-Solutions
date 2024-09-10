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

    int GCD(int a, int b)
    {
        if(b==0) return a;

        return GCD(b, a%b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while(cur->next)
        {
            ListNode* t = cur->next;
            cur->next = new ListNode(GCD(cur->val, t->val));
            cur->next->next = t;
            cur = t;
        }
        
        return head;
    }
};