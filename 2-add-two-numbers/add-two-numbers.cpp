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


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int c=0;
        while(l1 || l2 ||c){
            int a=0;
            if(l1){
                a+=l1->val;
                l1=l1->next;
            }
            if(l2){
                a+=l2->val;
                l2=l2->next;
            }
            a+=c;
            c=a/10;
            a=a%10;

             temp->next=new ListNode(a);
             temp=temp->next;
            
        }
        return dummy->next;

            
            
           
    }
};