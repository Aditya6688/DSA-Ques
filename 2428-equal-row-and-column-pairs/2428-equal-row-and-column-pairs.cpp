class Solution {
public:
    int equalPairs(vector<vector<int>>& mat) {
        map<vector<int>,int>m1;
        map<vector<int>,int>m2;
        int n=mat.size();
        for(int i=0; i<n; i++){
            vector<int>v;
            for(int j=0; j<n; j++) v.push_back(mat[i][j]);
            m1[v]++;
        }
        for(int i=0; i<n; i++){
            vector<int>v;
            for(int j=0; j<n; j++) v.push_back(mat[j][i]);
            m2[v]++;
        }
        int ans=0;
        for(auto it:m1){
            if(m2.find(it.first)!=m2.end()) ans+=(it.second*m2[it.first]);
        }
        return ans;
    }
};