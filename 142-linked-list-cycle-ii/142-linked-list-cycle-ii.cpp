/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head,*fast=head;
        while(fast and fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
            {
                fast=head;
                while(fast)
                {
                if(fast==slow)
                    return slow;
                slow=slow->next;
                fast=fast->next;
                }
            }
        }
        return NULL;
    }
};