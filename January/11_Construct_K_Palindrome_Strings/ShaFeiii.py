class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        if len(s) == k: return True
        if len(s) < k: return False

        odd = 0
        for c in s:
            odd ^= 1 << (ord(c) - ord('a'))
        return bin(odd).count('1') <= k