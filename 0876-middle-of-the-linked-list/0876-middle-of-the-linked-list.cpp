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
    ListNode* middleNode(ListNode* head) {
        ListNode* current = head;
        int n = 0;

        while (current != NULL){
            n ++;
            current = current -> next;
        }
        ListNode* mid_node = head;
        int mid = n/2;
        while (mid--){
            mid_node = mid_node -> next;
        }
        return mid_node;

    }
};