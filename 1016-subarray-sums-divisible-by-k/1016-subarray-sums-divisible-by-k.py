class Solution(object):
    def subarraysDivByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        count = 0
        prefix_sum = 0
        prefix_map = {0: 1}  
        
        for num in nums:
            prefix_sum += num
            mod = prefix_sum % k
            if mod < 0:  
                mod += k
            if mod in prefix_map:
                count += prefix_map[mod]
                prefix_map[mod] += 1
            else:
                prefix_map[mod] = 1
        
        return count
