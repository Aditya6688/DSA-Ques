class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        cnt = 0
        res = []
        n = len(nums)
        for i in range(n):
            for j in range(n):
                if i!=j and nums[j] < nums[i]:
                    cnt+=1
            
            res.append(cnt)
            cnt = 0

        return res