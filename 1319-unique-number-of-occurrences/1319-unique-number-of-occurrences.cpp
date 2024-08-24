class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n = arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        set<int>s;
        for(auto x:mp){
            s.insert(x.second);
        }

        return s.size() == mp.size();
    }
};