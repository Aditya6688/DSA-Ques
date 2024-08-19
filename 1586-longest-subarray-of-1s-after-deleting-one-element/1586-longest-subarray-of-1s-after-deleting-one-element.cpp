class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start=0,end,count=0;
    
        for(end=0;end<nums.size();end++)
        {
            if(nums[end]==0) count++;
            if(count>1)
            {
                
                if(nums[start]==0) 
                {
                    count--;
                }
                start++;
            }
        }
        return end-start-1;
    }
};