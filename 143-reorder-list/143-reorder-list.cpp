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
    void reorderList(ListNode* head) {
         if(!head || !(head->next) || !(head->next->next)) return;
   
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
      
        ListNode* head2 = slow->next;
        slow->next = NULL;
        
        
        head2 = reverse(head2);
        
        
        ListNode* h = head;
        while(head2)
        {
            ListNode* temp=head2->next;
            head2->next=h->next;
            h->next=head2;
            head2=temp;
            h=h->next->next;
        }
     
    }
};


