class Solution:
    def nthUglyNumber(self, n: int) -> int:
        nums = [1, 2, 3, 4, 5]
        if n <= len(nums):
            return nums[n - 1]
        # define three pointers
        p2 = 2
        p3 = 1
        p5 = 1
        for _ in range(5, n):
            next_target = min(nums[p2] * 2, nums[p3] * 3, nums[p5] * 5)
            nums.append(next_target)
            if next_target % 2 == 0:
                p2 += 1
            if next_target % 3 == 0:
                p3 += 1
            if next_target % 5 == 0:
                p5 += 1
        return nums[n - 1]


if __name__ == '__main__':
    sol = Solution()
    print(sol.nthUglyNumber(7))
