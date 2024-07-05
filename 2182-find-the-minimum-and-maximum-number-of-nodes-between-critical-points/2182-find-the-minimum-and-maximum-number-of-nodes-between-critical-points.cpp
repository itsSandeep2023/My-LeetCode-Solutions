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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int mn = 1e5 + 1, mx{0};
        ListNode *p = head, *c = head->next, *n = c->next;
        int a{0};
        int i{1};
        while (n) {
            int pv = p->val, cv = c->val, nv = n->val;
            if (cv > pv and cv > nv or (cv < pv and cv < nv)) {
                if(a==0)
                {
                    a=i;
                }
                else
                {
                    mn = min(mn, i-a-mx);
                    mx = max(mx, i-a);
                }
            }

            i++;
            p = c;
            c = n;
            n = n->next;
        }
        if (mn == 1e5 + 1 or mx == 0)
            return {-1, -1};

        return {mn, mx};
    }
};