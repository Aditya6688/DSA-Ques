class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        if(n%2 != 0){
            for(int j=-(n/2);j<=(n/2);j++) v.push_back(j);
        }
        else{
            for(int j=-(n/2);j<=(n/2);j++){
                if(j != 0) v.push_back(j);
            }
        }
        return v;
    }
};