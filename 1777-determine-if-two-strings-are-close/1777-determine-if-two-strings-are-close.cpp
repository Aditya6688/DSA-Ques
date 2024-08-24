class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if(n != m) return false;
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<n;i++){
            mp1[word1[i]]++;
        }
        for(int i=0;i<m;i++){
            mp2[word2[i]]++;
        }
        vector<int> v1,v2;
        vector<char> s1,s2;
        for(auto x:mp1){
            v1.push_back(x.second);
            s1.push_back(x.first);
        }
        for(auto x:mp2){
            v2.push_back(x.second);
            s2.push_back(x.first);
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        return (v1 == v2 and s1 == s2);
    }
};