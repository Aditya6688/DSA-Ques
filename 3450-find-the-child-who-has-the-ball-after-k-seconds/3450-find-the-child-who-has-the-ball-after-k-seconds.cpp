class Solution {
public:
    int numberOfChild(int n, int k) {
        int a = 0;
        int cnt;
        while(k){
            if(a == 0){
                cnt = 1;
            }
            if(a == n-1){
                cnt = -1;
            }
            a = a+cnt;
            k--;
        }
        return a;
    }
};