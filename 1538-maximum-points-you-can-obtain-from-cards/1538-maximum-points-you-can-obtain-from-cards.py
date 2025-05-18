class Solution(object):
    def maxScore(self, cardPoints, k):
        """
        :type cardPoints: List[int]
        :type k: int
        :rtype: int
        """
        n = len(cardPoints)
        res = 0
        for i in range(k):
            res+=cardPoints[i]

        curr = res
        for i in range(k-1,-1,-1):
            curr -= cardPoints[i]
            curr += cardPoints[n-k+i]

            res = max(res,curr)

        return res