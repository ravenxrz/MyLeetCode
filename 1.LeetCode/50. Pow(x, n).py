from typing import List


class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        # negative check
        if n < 0:
            x = 1 / x
            n = -n
        return self.powCore(x, n)

    # return pow(x,n)

    # acquired: n > 0
    def powCore(self, x: float, n: int) -> float:
        if n == 1:
            return x
        if n % 2 == 0:
            half = self.powCore(x, n // 2)
            return half * half
        else:
            half = self.powCore(x, (n - 1) // 2)
            return x * half * half


if __name__ == '__main__':
    sol = Solution()
    print(sol.myPow(2.1, 3))
    print(sol.myPow(2, -2))
