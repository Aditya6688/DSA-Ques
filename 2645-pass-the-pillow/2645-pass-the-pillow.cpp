class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 0;
        int g = 1;
        while(time){
            if(i == 0) g = 1;
            if(i == n-1) g = -1;

            i+=g;
            time--;
        }
        return i+1;
    }
};