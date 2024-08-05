class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> m;
        string ans;
        int n = arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(m[arr[i]] == 1){
                ans = arr[i];
                k--;
            }
            if(k == 0) break;
        }
        if(k == 0)
        return ans;
        else
        return "";
    }
};