class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow) {
                ListNode* entry = head;

                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }

                return entry;
            }
        }

        return NULL;
    }
};