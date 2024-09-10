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
        if(a<b) swap(a, b);
        
        for(int i{1}; i<=(b/2); i++)
        {
            int c = b/i;
            cout<<c<<" ";

            if(a%c == 0 and b%c == 0)
                return c;
        }

        return 1;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios::sync_with_stdio(false);
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