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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* current = head;
        int n = 0;

        while (current != NULL){
            n++;
            current = current -> next;
        }
        ListNode* mid_node = head;
        int mid = n / 2;
        while (mid--){
            mid_node = mid_node -> next;
        }

        ListNode* temp = head;
        while (temp->next != mid_node) {
            temp = temp->next;
        }

        temp->next = mid_node->next;
        delete mid_node;

        return head;
    }
};