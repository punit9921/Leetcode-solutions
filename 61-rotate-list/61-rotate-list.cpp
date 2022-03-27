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
    ListNode* rotateRight(ListNode* head, int k) {
     if(head==NULL)
         return NULL;
        ListNode* curr=head;
        int n=0;
        while(curr->next)
        {
            
            n++;
            curr=curr->next;
        }
        n++;
        curr->next=head;
        if(n<k)
        k%=n;
      
        for(int i=0;i<n-k;i++)
        {
            curr=curr->next;
        }
        ListNode* ans=curr->next;
        curr->next=NULL;
        return ans;
    }
};