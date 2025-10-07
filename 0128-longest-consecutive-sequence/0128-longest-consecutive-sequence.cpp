class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int n = nums.size();
        int res = 0;

        for(int num:s){
            int x = 1;
            if(s.find(num-1) == s.end()){
                int cnt = 1;
                while(s.find(num+x) != s.end()){
                    cnt++;
                    x++;
                }
                res = max(res,cnt);
            }
        }

        return res;
    }
};