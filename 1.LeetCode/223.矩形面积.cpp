/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    
    unsigned int computeIntersect(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        if (C < E || B > H || D < F) return 0;
        unsigned int deltax = min(C, G) - max(A, E);
        unsigned int deltay = min(D, H) - max(B, F);
        return deltax * deltay;
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        const unsigned int area1 = (C - A) * (D - B);
        const unsigned int area2 = (H - F) * (G - E);
        /* 包含关系 */
        if (A < E && C > G && B < F && D > H) {        /* 矩阵1包含矩阵2 */
            return area1;
        } else if (A > E && C < G && B > F && D < H) {             /* 矩阵2包含矩阵1 */
            return area2;
        }
        
        unsigned  int sum = area1 + area2;
        /* 相交关系 */
        if (A < E) return sum - computeIntersect(A, B, C, D, E, F, G, H);
        else return sum - computeIntersect(E, F, G, H, A, B, C, D);
    }
};
// @lc code=end

int main()
{
    Solution sol;
    std::cout << sol.computeArea(-2,-2,2,2,-1,4,1,6);
    return 0;
}