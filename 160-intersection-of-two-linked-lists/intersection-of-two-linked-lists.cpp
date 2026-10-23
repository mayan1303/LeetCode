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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a=0;
        int b=0;
        ListNode*c1=headA;
        ListNode*c2=headB;
        while(c1!=NULL){
            c1=c1->next;
            a++;
        }
        while(c2!=NULL){
            c2=c2->next;
            b++;
        }
        int d=abs(a-b);
        
        ListNode*temp1=headA;
        ListNode*temp2=headB;
        if(a>b){
            for(int i=0;i<d;i++){
                temp1=temp1->next;
            }
        }
        else{
            for(int i=0;i<d;i++){
                temp2=temp2->next;
            }
        }
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;

    }
};