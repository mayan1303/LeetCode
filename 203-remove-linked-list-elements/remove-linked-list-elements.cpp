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
    ListNode* deleteElement(ListNode* head, int ind){
        if(ind==0){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode* temp=head;
        for(int i=0;i<ind-1;i++){
            if(!temp->next) return head;
            temp=temp->next;
        }

        if(!temp->next) return head;

        ListNode* del=temp->next;
        temp->next=del->next;
        delete del;
        return head;
    }
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode* temp=head;
        int i=0;
        while(temp){
            if(temp->val==val){
                head= deleteElement(head,i);
                temp=head;
                i=0;
            }
            else{
                i++;
                temp=temp->next;
            }
            
            
        }
        return head;
    }
};