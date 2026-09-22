class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* before = dummy;

        // Move before to the node just before left
        for (int i = 1; i < left; i++) {
            before = before->next;
        }

        ListNode* l = before->next;
        ListNode* curr = l;
        ListNode* prev = NULL;

        // Reverse left to right
        for (int i = 0; i < right - left + 1; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Connect the reversed portion
        before->next = prev;
        l->next = curr;

        return dummy->next;
    }
};