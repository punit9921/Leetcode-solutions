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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL,*curr=head,*next=NULL;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        ListNode* slow=head,*fast=head;
        if(!head or !head->next)
            return true;
        while(fast->next and fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            
        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        while(slow)
        {
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};