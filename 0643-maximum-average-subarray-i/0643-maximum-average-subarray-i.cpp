class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double res = 0, sum = 0;
        int j =0; 
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(i == k-1)
            res = sum/k;
            if(i>=k){
                sum-=nums[j];
                j++;
                res = max(res,sum/k);
            }
        }
        return res;
    }
};