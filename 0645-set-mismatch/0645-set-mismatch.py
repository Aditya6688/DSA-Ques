class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        s = set()
        dup = -1

        # Find the duplicated number
        for x in nums:
            if x in s:
                dup = x
            s.add(x)

        # Missing number = expected sum - (actual sum - duplicate)
        missing = (n * (n + 1)) // 2 - (sum(nums) - dup)

        return [dup, missing]


