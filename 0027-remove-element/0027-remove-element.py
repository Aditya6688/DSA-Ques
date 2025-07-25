class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        v = [num for num in nums if num != val]
        for i in range(len(v)):
            nums[i] = v[i]
        return len(v)
        