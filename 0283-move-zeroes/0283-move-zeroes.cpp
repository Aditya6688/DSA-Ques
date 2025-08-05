class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int cz = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0) cz++;
        }

        int j = 0;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }

        for(int i=n-cz;i<n;i++){
            nums[i] = 0;
        }
    }
};