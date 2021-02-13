

class Solution {
public:
    int lastRemaining(int n, int m)
    {
        if (n == 1) return 0;
        int lastF = 0;
        for (int i = 2; i <= n; i++) {
            lastF = (lastF + m) % i;
        }
        return lastF;
    }
};
