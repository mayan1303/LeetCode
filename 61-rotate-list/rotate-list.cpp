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

    ListNode* rotate(ListNode* head){
        if (head == NULL || head->next == NULL)
            return head;
        ListNode*temp=head;
        while(temp->next->next){
            temp=temp->next;
        }
        ListNode*curr=temp->next;
        temp->next=NULL;
        curr->next=head;
        return curr;
    }



    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
        return head;
        ListNode*temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        int r=k%n;
        for(int i=0;i<r;i++){
            head= rotate(head);
        }
        return head;
    }
};