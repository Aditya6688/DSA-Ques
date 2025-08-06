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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) return nullptr;
        if (!list1) return list2;
        if (!list2) return list1;

        vector<int> vals;
        for (ListNode* curr = list1; curr; curr = curr->next)
            vals.push_back(curr->val);

        for (ListNode* curr = list2; curr; curr = curr->next)
            vals.push_back(curr->val);

        sort(vals.begin(), vals.end());
        ListNode* curr = list1;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = list2;
        ListNode* temp = list1;
        for (int v : vals) {
            temp->val = v;
            temp = temp->next;
        }
        return list1;
    }
};