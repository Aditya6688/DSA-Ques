class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> ch;

        for(int i=0;i<nums.size();i++){
            ch[nums[i]]++;
        }

        for(auto j:ch){
            if(j.second==1){
                return j.first;
            }
        }

        return 0;
    }
};