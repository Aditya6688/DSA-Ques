class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zc = 0, oc = 0, tc = 0;
        for(int num:nums){
            if(num == 0) zc++;
            else if(num == 1) oc++;
            else tc++;
        }

        for(int i=0;i<n;i++){
            if(zc>0){
                nums[i] = 0; zc--;
            }
            else if(oc>0){
                nums[i] = 1; oc--;
            }
            else{
                nums[i] = 2; tc--;
            }
        }

        // int i=0;
        // while(zc>0){
        //     nums[i] = 0;
        //     i++;
        // }
        // while(oc>0){
        //     nums[i] = 1;
        //     i++;
        // }
        // while(tc>0){
        //     nums[i] = 2;
        //     i++;
        // }
    }
};