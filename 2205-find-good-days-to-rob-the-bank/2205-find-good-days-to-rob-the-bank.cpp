class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& arr, int time) {
        int n = arr.size(),i;
        vector<int> in(n,1),de(n,1),ans;
        for(i = 1; i < n; i++){
            if(arr[i]<=arr[i-1]){
                in[i] += in[i-1];
            }
        }
        for(i = n-2; i >= 0; i--){
            if(arr[i]<=arr[i+1]){
                de[i] += de[i+1];
            }
        }
        for(i = 0; i < n; i++){
            if(in[i]>time && de[i]>time){
                ans.push_back(i);
            }
        }
        return ans;
    }
};