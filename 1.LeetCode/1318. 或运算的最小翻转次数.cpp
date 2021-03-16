class Solution {
public:
    int minFlips(int a, int b, int c)
    {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int bita = (a >> i) & 1;
            int bitb = (b >> i) & 1;
            int bitc = (c >> i) & 1;
            if (bitc == 1) {
                ans += (bita | bitb ? 0 : 1);
            } else {
                if (bita & bitb) ans += 2;     // 1 1
                else if (bita | bitb) ans += 1;   // 1 0 or 0 1
            }
        }
        return ans;
    }
};
