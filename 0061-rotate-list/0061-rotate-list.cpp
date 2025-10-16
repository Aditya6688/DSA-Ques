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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head) return head;
        vector<int> v;

        ListNode* curr = head;
        while(curr){
            v.push_back(curr->val);
            curr = curr->next;
        }

        int n = v.size();
        vector<int> v2(n);
        if(k>=n) k = k%n;
        for(int i=0;i<n;i++){
            v2[i] = v[(i+n-k)%n];
        }

        ListNode* temp = new ListNode(v2[0]);
        ListNode* dummy = temp;
        for(int i=1;i<n;i++){
            dummy->next = new ListNode(v2[i]);
            dummy = dummy->next;
        }

        return temp;
    }
};