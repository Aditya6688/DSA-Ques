class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        mr = 0
        for i in range(len(nums)):
            if(i>mr):
                return False

            mr = max(mr, i+nums[i])

            if(mr>len(nums)-1):
                return True

        return True