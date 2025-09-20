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
    ListNode* func(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int cnt = 0;

        while(curr && cnt<k){  
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        if(next){
            ListNode* temp = func(next,2);
            head->next = temp;
        }
        
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* res = func(head,2);
        return res;
    }
};