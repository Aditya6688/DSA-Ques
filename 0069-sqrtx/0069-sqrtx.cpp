class Solution {
public:
    int mySqrt(int x) {
        long long ans = 0;
        if(x==0) return 0;
        if(x<4) return 1;

        for(long long i=1;i*i<=x;i++){
            if(i*i>x){
                ans = i-1;
                break;
            }
            ans = i;
        }
        return ans;
    }
};