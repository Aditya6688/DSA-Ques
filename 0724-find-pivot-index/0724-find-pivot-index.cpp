class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int lsum = 0, rsum = 0;
        int sum1 = 0, sum2 = 0;

        for(int i=1;i<n;i++) sum1+=nums[i];
        if(sum1 == 0) return 0;

        for(int i=1;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                lsum+=nums[j];
            }
            for(int j=0;j<i;j++){
                rsum+=nums[j];
            }
            if(lsum ==  rsum) return i;
            lsum = 0; rsum = 0;
        }

        for(int i=n-2;i>=0;i--) sum2+=nums[i];
        if(sum2 == 0) return n-1;
        
        return -1;
    }
};