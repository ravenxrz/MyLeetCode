class Solution:

    def getKthMagicNumber(k: int) -> int:
        nums = [1, 3, 5, 7, 9, 15, 21]
        if k <= len(nums):
            return nums[k - 1]
        p3 = 4
        p5 = 2
        p7 = 2
        old_len = len(nums)
        for _ in range(old_len, k):
            next_target = min(nums[p3] * 3, nums[p5] * 5, nums[p7] * 7)
            nums.append(next_target)
            if next_target % 3 == 0:
                p3 += 1
            if next_target % 5 == 0:
                p5 += 1
            if next_target % 7 == 0:
                p7 += 1
        return nums[k - 1]


if __name__ == '__main__':
    sol = Solution()
    print(sol.getKthMagicNumber(10))
