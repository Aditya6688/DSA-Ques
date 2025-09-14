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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        int n = lists.size();
        ListNode* curr = nullptr;
        for(int i=0;i<n;i++){
            curr = lists[i];
            while(curr){
                v.push_back(curr->val);
                curr = curr->next;
            }
        }

        if(v.size() == 0) return NULL;

        sort(v.begin(),v.end());

        ListNode* head  = new ListNode(v[0]);
        if(v.size() == 1) return head;
        ListNode* dummy = head;
        for(int i=1;i<v.size();i++){
            dummy->next = new ListNode(v[i]);
            dummy = dummy->next;
        }

        return head;
    }
};