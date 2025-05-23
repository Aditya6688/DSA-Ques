class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = {}
        n = len(nums)
        target = n // 2

        for num in nums:
            count[num] = count.get(num, 0) + 1

        for key, val in count.items():
            if val > target:
                return key