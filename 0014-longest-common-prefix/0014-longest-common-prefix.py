class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
            
        strs.sort()
        start = strs[0]
        end = strs[-1]
        ans = ""

        for i in range(min(len(start), len(end))):
            if start[i] != end[i]:
                return ans
            ans += start[i]

        return ans 
