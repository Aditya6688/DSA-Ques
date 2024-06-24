class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double>res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0,j=n-1;
        while(i<j){
            double a = (double(nums[i])+double(nums[j]))/2;
            res.push_back(a);
            i++; j--;
        }
        sort(res.begin(),res.end());
        return res[0];
    }
};