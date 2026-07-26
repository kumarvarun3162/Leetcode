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
    void reorderList(ListNode* head) {
        if (head == NULL || head -> next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while ( fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* second = slow -> next;
        ListNode* prev = NULL;
        slow -> next = NULL;

        while (second != NULL){
            ListNode* nextNode = second -> next;
            second -> next = prev; 
            prev = second;
            second = nextNode;
        }

        ListNode* first = head;
        second = prev;

        while (second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }

    }
};