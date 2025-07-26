class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), i=0,j=0;
        vector<int> v;
        if(n == 1){
            return 1;
        }
        while(i<n){
            if(i == 0){
                v.push_back(nums[i]);
                i++;
            } 

            if(nums[i] == nums[j]){i++; j++;}
            else{
                v.push_back(nums[i]);
                i++; j++;
            }
        }

        int m = v.size();
        for(int i=0;i<m;i++){
            nums[i] = v[i];
        }
        return m;
    }
};