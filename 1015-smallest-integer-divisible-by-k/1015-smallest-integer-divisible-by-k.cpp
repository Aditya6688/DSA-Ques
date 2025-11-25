class Solution {
public:
    int smallestRepunitDivByK(int k) {
        long long a  = 1;
        if(k%2 == 0 || k % 5 == 0) return -1;
        int ans = -1, cnt = 0;

        while(cnt<k){
            if(a%k == 0){
                ans = a;
                break;
            } 
            else a = (a*10 + 1)%k;
            cnt++;
        }
        if(ans == -1) return ans;
        else return cnt+1;
    }
};