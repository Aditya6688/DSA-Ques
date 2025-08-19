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
    ListNode* sortList(ListNode* head) {
        vector<int> res;
        ListNode* curr = head;
        while(curr){
            res.push_back(curr->val);
            curr = curr->next;
        }

        curr = head;
        sort(res.begin(),res.end());
        int i = 0;
        while(curr){
            curr->val = res[i];
            curr = curr->next;
            i++;
        }
        return head;
    }
};