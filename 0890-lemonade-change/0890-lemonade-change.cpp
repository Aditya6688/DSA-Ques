class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[bills[i]]++;
            if(bills[i] == 10){
                if(m[5]==0) return false;
                else m[5]--;
            }
            else if(bills[i] == 20){
                if(m[5]==0) return false;
                if(m[5]<3 and m[10] == 0) return false;
                else{
                    if(m[10] == 0) m[5] = m[5]-3;
                    else{
                        m[10]--; m[5]--;
                    }
                }
            }
        }
        return true;
    }
};