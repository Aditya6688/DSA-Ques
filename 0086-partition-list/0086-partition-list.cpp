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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;

        vector<int> v1, v2;
        ListNode* curr = head;
        while(curr){
            if(curr->val < x) v1.push_back(curr->val);
            else v2.push_back(curr->val);
            curr = curr->next;
        }

        curr = head;
        for(int i=0;i<v1.size();i++){
            curr->val = v1[i];
            curr = curr->next;
        }
        for(int i=0;i<v2.size();i++){
            curr->val = v2[i];
            curr = curr->next;
        }

        return head;
    }
};