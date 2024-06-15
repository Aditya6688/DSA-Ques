class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefixArr(n);
        prefixArr[0] =nums[0];

        for(int i=1; i<n; i++){
            prefixArr[i] = prefixArr[i-1]*nums[i];
        }

        vector<int> suffixArr(n);
        suffixArr[n-1] =nums[n-1];

        for(int i=n-2; i>=0; i--){
            suffixArr[i] = suffixArr[i+1]*nums[i];
        }

        vector<int> result(n);
        result[0] = suffixArr[1];
        result[n-1]= prefixArr[n-2];
        for(int i=1; i<n-1; i++){
            result[i] = prefixArr[i-1] * suffixArr[i+1];
        }
        return result;
    }
};