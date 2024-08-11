class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(m == 1 and flowerbed[0] == 1){
            return true?(n == 0):false;
        }
        if(m == 1 and flowerbed[0] == 0){
            return true?(n <= 1):false;
        }
        int i=0, cnt = 0;;
        while(i<m){
            if(i == 0 and flowerbed[i] == 0 and flowerbed[i+1] == 0){
                cnt++;
                flowerbed[i] = 1;
            }
            if(i>0 and i<m-1){
                if(flowerbed[i] == 0 and flowerbed[i-1] == 0 and flowerbed[i+1] == 0){
                    cnt++; flowerbed[i] = 1;
                } 
            }
            if(i == m-1 and flowerbed[i] == 0 and flowerbed[i-1] == 0){
                cnt++; flowerbed[i] = 1;
            }
            i++;
        }
        if(cnt>=n)
        return true;
        else
        return false;
    }
};