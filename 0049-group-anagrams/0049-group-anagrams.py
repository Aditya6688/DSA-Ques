class Solution(object):
    from collections import defaultdict

    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        mp = defaultdict(list)

        for s in strs:
            key = ''.join(sorted(s))  # sorted string as key
            mp[key].append(s)

        return list(mp.values())