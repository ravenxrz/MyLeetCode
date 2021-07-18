class Solution {
   public:
    int numWays(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 1;
        long long a = 1;
        long long b = 1;
        long long c;
        for (int i = 2; i <= n; i++) {
            c = (a + b) % static_cast<long long>(1e9 + 7);
            a = b;
            b = c;
        }
        return c;
    }
};