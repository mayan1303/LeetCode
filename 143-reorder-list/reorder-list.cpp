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
    ListNode* rev(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;

            prev=curr;
            curr=next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next ) return;
        ListNode* curr=head;
        ListNode* slow=head;
        ListNode* fast=head;
       

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *mid=slow->next;
        slow->next=NULL;
        mid=rev(mid);
        
        while(curr && mid){
            ListNode* n1=curr->next;
            ListNode* n2=mid->next;

            curr->next=mid;
            mid->next=n1;

            curr=n1;
            mid=n2;
        }
        
    }
};