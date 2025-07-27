class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1;
        int res = 0, ans = 0;
        while(i<j){
            res = min(height[i],height[j])*(j-i);
            if(height[i]<height[j]){
                i++;
            }
            else if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
                j--;
            }
            ans = max(ans,res);
        }
        return ans;
    }
};