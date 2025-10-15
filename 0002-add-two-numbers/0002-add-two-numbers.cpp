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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return nullptr;
        vector<int> res;
        int carry = 0;

        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            res.push_back(sum%10);
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int sum = l1->val + carry;
            res.push_back(sum%10);
            carry = sum/10;
            l1 = l1->next;
        }

        while(l2){
            int sum = l2->val + carry;
            res.push_back(sum%10);
            carry = sum/10;
            l2 = l2->next;
        }
        if(carry) res.push_back(carry);

        
        ListNode* head = new ListNode(res[0]);
        ListNode* curr = head;
        for(int i=1;i<res.size();i++){
            curr->next = new ListNode(res[i]);
            curr = curr->next;
        }

        return head;
    }
};