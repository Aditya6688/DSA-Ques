class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int n = height.size();
        int maxi = height[0];
        if(n<3) return 0;
        int ind = 0;

        for(int i=1;i<n;i++){
            if(maxi>height[i]){
                sum += (maxi-height[i]);
            }
            else{
                maxi = height[i];
                ind = i;
            }
        }

        if(ind == n-1) return sum;
        int rmaxi = height[n-1];
        sum -= (maxi-rmaxi);

        for(int i=n-2;i>=ind;i--){
            if(height[i]>rmaxi){
                rmaxi = height[i];
                sum -= (maxi-rmaxi);
            }
            else{
                sum -= (maxi-rmaxi);
            }
        }
        return sum;
    }
};