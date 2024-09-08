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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* cur = head;
        int n{0};

        while (cur) {
            cur = cur->next;
            n++;
        }

        int r = n % k;
        n = n / k;

        ListNode* nxt = head;

        vector<ListNode*> ans(k, NULL);

        for (int i{0}; i < k and nxt; i++) {
            ans[i] = nxt;

            for (int cnt{0}; cnt < n + (r > 0 ? 1 : 0); cnt++) {
                cur = nxt;
                nxt = nxt->next;
            }

            cur->next = NULL;
            r--;
        }

        return ans;
    }
};