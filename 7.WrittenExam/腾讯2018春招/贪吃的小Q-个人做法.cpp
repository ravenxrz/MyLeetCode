#include <bits/stdc++.h>

using namespace std;


/**
 * 递归超时
 */
int ans = 0;

bool check(int curPieces, int curTotalPieces, int totalPieces, int curDay, int targetDay)
{
    if (curDay == targetDay) {
        if (curTotalPieces <= totalPieces) {
            ans = curPieces;
            return true;
        }
        return false;
    }
    if (curTotalPieces >= totalPieces) return false;
    
    return check(curPieces << 1, curTotalPieces + (curPieces << 1), totalPieces, curDay + 1, targetDay) ||
           check((curPieces << 1) - 1, curTotalPieces + (curPieces << 1) - 1, totalPieces, curDay + 1, targetDay);
}

int main()
{
    int n, m;
    cin >> n >> m;
    ans = 0;

//    for (int k = 0; k <= n; k++) {
//        // 吃了k天一块
//        if (check(1, 1, m, k + 1, n)) break;
//    }
    cout << ans << endl;
    return 0;
}
