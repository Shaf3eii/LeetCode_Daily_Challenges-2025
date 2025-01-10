class Solution(object):
    def waysToSplitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tot = sum(nums)
        cur = 0
        splits = 0
        for i in range(0, len(nums) - 1):
            tot -= nums[i]
            cur += nums[i]
            if cur >= tot:
                splits += 1

        return splits