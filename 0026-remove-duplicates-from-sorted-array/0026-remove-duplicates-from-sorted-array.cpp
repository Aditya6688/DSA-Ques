class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;
        if(n == 1) return n;
        
        while(j<n){
            if(nums[i] == nums[j]) j++;
            else{
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        return i+1;
    }
};