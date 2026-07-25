class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* current = head;
        int n = 0;

        while (current != nullptr) {
            n++;
            current = current->next;
        }

        int mid = n / 2;

        ListNode* mid_node = head;
        while (mid--) {
            mid_node = mid_node->next;
        }

        return mid_node;
    }
};