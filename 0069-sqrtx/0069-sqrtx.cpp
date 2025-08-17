class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        if(x == 0) return 0;
        if(x<=3) return 1;
        for(long long i=0;i<=x/2+1;i++){
            if(i*i == x){
                res = i;
                break;
            }
            else if(i*i>x){
                res = i-1;
                break;
            }
        }
        return res;
    }
};