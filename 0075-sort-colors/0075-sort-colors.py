class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        cntz = 0
        cnto = 0
        cntt = 0

        for i in range(len(nums)):
            if nums[i] == 0:
                cntz+=1
            elif nums[i] == 1:
                cnto+=1
            else:
                cntt+=1

        j = 0
        while(cntz>0):
            nums[j] = 0
            j+=1
            cntz-=1

        while(cnto>0):
            nums[j] = 1
            j+=1
            cnto-=1

        while(cntt>0):
            nums[j] = 2
            j+=1
            cntt-=1

        return nums