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
        if(!head || !head->next){
            return NULL;
        }
        
        ListNode *slow=head;
        ListNode *p1=head;
        ListNode *fast=head;
        ListNode *p2;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                p2=slow;
                while(p1!=p2){
                p1=p1->next;
                p2=p2->next;
                
            }
            return p1;
            }
        }
        
        return NULL;
    }

};