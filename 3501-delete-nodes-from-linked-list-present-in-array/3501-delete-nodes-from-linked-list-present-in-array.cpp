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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(auto&x:nums)
        {
            st.insert(x);
        }

        ListNode* p=nullptr;
        ListNode* c=head;

        while(c)
        {
            if(st.count(c->val))
            {
                ListNode* temp = c;
                if(p)
                {
                    p->next = c->next;
                }
                else
                {
                    head=head->next;
                }
                c=c->next;
                delete temp;
            }
            else
            {
                p=c;
                c=c->next;
            }
        }

        return head;
    }
};