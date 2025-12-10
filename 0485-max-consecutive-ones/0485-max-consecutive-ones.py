class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = 0
        res = 0
        for x in nums:
            if x == 1:
                cnt += 1
            else:
                res = max(res,cnt)
                cnt = 0

        res = max(res,cnt)
        return res
        