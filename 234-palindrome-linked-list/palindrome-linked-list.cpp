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

    ListNode* revList(ListNode* head){
            ListNode* prev = NULL;
            ListNode* curr = head;

        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }


    bool isPalindrome(ListNode* head) {
        if(!head && !head->next){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*newHead=revList(slow->next);
        ListNode* c1=head;
        ListNode* c2=newHead;

        while(c2!=NULL){
            if(c1->val!=c2->val){
                return false;
            }
            c1=c1->next;
            c2=c2->next;
        }
        return true;
    }
};