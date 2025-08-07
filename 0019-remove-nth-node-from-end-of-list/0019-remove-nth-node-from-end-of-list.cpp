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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (head == nullptr || head->next == nullptr)
            return nullptr;

        int count = 0;
        ListNode* temp = head;

        // Calculate the number of nodes in the list
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // If the node to be removed is the head, return head->next
        if (count == n)
            return head->next;

        // Calculate the position of the node to be removed from the beginning of the list
        count = count - n;
        temp = head;

        // Iterate to the node just before the one to be removed
        while (count > 1) {
            temp = temp->next;
            count--;
        }

        // Remove the node by updating the pointers
        temp->next = temp->next->next;

        // Return the modified head of the list
        return head;
    }
};