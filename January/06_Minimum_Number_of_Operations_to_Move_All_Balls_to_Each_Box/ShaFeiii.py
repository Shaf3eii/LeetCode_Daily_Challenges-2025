class Solution(object):
    def minOperations(self, boxes):
        """
        :type boxes: str
        :rtype: List[int]
        """
        n = len(boxes)
        ans = []
        for i in range(n):
            left ,right, cnt = 0, 0, 0
            j ,k = i - 1, i + 1
            while j >= 0:
                cnt += 1
                left += (cnt if boxes[j] == '1' else 0)
                j -= 1
            cnt = 0
            while k < n:
                cnt += 1
                right += (cnt if boxes[k] == '1' else 0)
                k += 1
            ans.append(right + left)
        return ans
