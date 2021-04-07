from typing import List


class Solution:
    def pairSums(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        i = 0
        j = len(nums) - 1
        ans = []
        while i < j:
            tmp = nums[i] + nums[j]
            if tmp == target:
                ans.append([nums[i], nums[j]])
                i += 1
                j -= 1
            elif tmp > target:
                j -= 1
                while i < j and nums[i] + nums[j] > target:
                    j -= 1
            elif tmp < target:
                i += 1
                while i < j and nums[i] + nums[j] < target:
                    i += 1
        return ans


if __name__ == "__main__":
    sol = Solution()
    nums = [5, 6, 5, 6]
    target = 11
    print(sol.pairSums(nums, target))
