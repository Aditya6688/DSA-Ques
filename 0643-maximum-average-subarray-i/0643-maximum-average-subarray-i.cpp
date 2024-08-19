class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0.0;
        for(int i=0;i<k;i++) sum+= nums[i];
        double avg = sum/k;

        int i=0,j=k;
        while(j<n){
            sum-=nums[i];
            sum+=nums[j];
            i++; j++;
            avg = max(avg,sum/k);
        }

        return avg;
    }
};