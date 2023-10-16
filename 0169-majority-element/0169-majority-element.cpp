class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];

        // int n = nums.size();
        // unordered_map<int, int> m;
        
        // for(int i = 0; i < n; i++){
        //     m[nums[i]]++;
        // }
        // n = n/2;
        // for(auto x: m){
        //     if(x.second > n){
        //         return x.first;
        //     }
        // }
        // return 0;
    }
};