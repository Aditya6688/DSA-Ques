class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> v;
        int n = s1.size();
        int m = s2.size();
        string s = "";
        unordered_map<string,int> mp1,mp2;

        for(int i=0;i<n;i++){
            if(s1[i] != ' ') s+=s1[i];
            else{
                mp1[s]++;
                s.clear();
            }
        }
        mp1[s]++;
        s.clear();

        for(int i=0;i<m;i++){
            if(s2[i] != ' ') s+=s2[i];
            else{
                mp2[s]++;
                s.clear();
            }
        }
        mp2[s]++;
        s.clear();

        for(auto &x: mp1){
            if(x.second == 1 and mp2.find(x.first) == mp2.end()) v.push_back(x.first);
        }
        for(auto &y: mp2){
            if(y.second == 1 and mp1.find(y.first) == mp1.end()) v.push_back(y.first);
        }

        return v;
    }
};