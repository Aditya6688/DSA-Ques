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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        unordered_map<int,int> mp;
        vector<int> res;
        if(!head) return nullptr;
        if(!head->next) return head;

        while(curr){
            mp[curr->val]++;
            curr = curr->next;
        }

        for(auto& x:mp){
            if(x.second == 1) res.push_back(x.first);
        }
        if (res.empty()) return nullptr;
        sort(res.begin(),res.end());

        ListNode* head2 = new ListNode(res[0]);
        ListNode* curr2 = head2;

        for (int i = 1; i < res.size(); ++i) {
            curr2->next = new ListNode(res[i]);
            curr2 = curr2->next;
        }

        return head2;
    }
};