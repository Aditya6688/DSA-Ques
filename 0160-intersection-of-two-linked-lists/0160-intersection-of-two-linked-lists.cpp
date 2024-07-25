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
        if (!headA || !headB) {
            return nullptr;
        }
        
        // Calculate the lengths of both lists
        int lenA = 0, lenB = 0;
        ListNode *curA = headA, *curB = headB;
        while (curA) {
            lenA++;
            curA = curA->next;
        }
        while (curB) {
            lenB++;
            curB = curB->next;
        }
        
        // Align the starts of both lists
        curA = headA;
        curB = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                curA = curA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; i++) {
                curB = curB->next;
            }
        }
        
        // Traverse both lists together to find the intersection point
        while (curA && curB) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        
        return nullptr;
    }
};