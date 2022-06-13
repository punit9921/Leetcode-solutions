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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *fast = head, *slow = head, *pre = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = NULL;
        ListNode *p = sortList(head);
        ListNode *q = sortList(slow);
        return merge(p, q);
    }
    
    ListNode *merge(ListNode *p, ListNode *q) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (p && q) {
            if (p->val < q->val) {
                cur->next = p;
                p = p->next;
            } else {
                cur->next = q;
                q = q->next;
            }
            cur = cur->next;
        }
        if (p)
            cur->next = p;
        if (q)
            cur->next = q;
        return dummy->next;
    }
};