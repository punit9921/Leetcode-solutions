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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1=new ListNode(-1),*h2=new ListNode(-1);
        ListNode*curr1=h1,*curr2=h2;
        while(head!=NULL)
        {
            if(head->val<x)
            {
                curr1->next=head;
                curr1=curr1->next;
            }
            else
            {
                curr2->next=head;
                curr2=curr2->next;
            }
            head=head->next;
        }
        curr2->next=NULL;
        curr1->next=h2->next;
        return h1->next;
    }
};