# Naive Algorithm
class Solution(object):
    def stringMatching(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        ans = []
        for i in range(len(words)):
            for j in range(len(words)):
                if j == i: continue
                if words[i] in words[j]:
                    ans.append(words[i])
                    break
        return ans