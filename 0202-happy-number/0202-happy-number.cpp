class Solution {
public:
    bool isHappy(int n) {
        int cnt = 0;
        int sum = 0;
        while(cnt<100){
            sum+=pow((n%10),2);
            n = n/10;
            if(n == 0){
                n = sum;
                if(sum == 1) return true;
                else sum = 0;
            } 
            cnt++;
        }
        return false;
    }
};