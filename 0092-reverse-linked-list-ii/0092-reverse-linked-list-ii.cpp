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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;
        ListNode* curr = head;
        int cnt = 0;
        while(curr){
            cnt++;
            if(cnt>=left&&cnt<=right) v.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        int n = v.size();
        int i = n-1;
        cnt = 0;
        while(curr){
            cnt++;
            if(cnt>=left&&cnt<=right){
                curr->val = v[i];
                i--;
            }
            curr = curr->next;
        }
        return head;
    }
};