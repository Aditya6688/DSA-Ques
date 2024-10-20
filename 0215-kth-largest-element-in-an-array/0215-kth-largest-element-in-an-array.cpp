class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(), nums.end());
        if(k == 1)
        return pq.top();

        while(k != 1){
             int a = pq.top();
             pq.pop();
             k--;
        }
        return pq.top();
    }
};