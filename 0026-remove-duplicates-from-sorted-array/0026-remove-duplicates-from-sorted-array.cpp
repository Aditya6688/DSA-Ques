class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());

        int i = 0;
        for(int x:s){
            nums[i] = x;
            i++;
        }
        // reverse(nums.begin(),nums.end());

        int k = s.size();
        return k;
    }
};