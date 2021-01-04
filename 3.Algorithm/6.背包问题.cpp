#include <iostream>
#include <vector>

using namespace std;


// 自顶向下，无记忆功能
void method1(const vector<int> &values, const vector<int> &weights, int capacity)
{
    const int m = weights.size();
    // 声明dp table
    vector<vector<int>> dp(m + 1, vector<int>(capacity + 1, -1));
    // 初始化dp table， 第0行和第0列初始化0
    for (int j = 0; j <= capacity; j++) {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    // 计算dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (j < weights[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j],
                               values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }
        }
    }
    cout << "max value:" << dp[m][capacity] << endl;;
    // 输出一个最优解
    vector<bool> bitmap(m, false);
    int i = m, j = capacity;
    while (i != 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            bitmap[i - 1] = true;
            j -= weights[i - 1];
        }
        i--;
    }
    cout << "one solution:[";
    for (int i = 0; i < bitmap.size(); i++) {
        if (bitmap[i]) cout << i + 1 << "(" << values[i] << ")" << ",";
    }
    cout << "]" << endl;
}

// 自底向上，有记忆功能
/**
 * @param i  放置第几个
 * @param j  当前剩余容量
 */
int MFSKnapsack(vector<vector<int>> &dp, const vector<int> &values, const vector<int> &weights, int i, int j)
{
    if (i < 0 || j < 0) return 0;
    int value = 0;
    if (j < weights[i]) {
        value = MFSKnapsack(dp, values, weights, i - 1, j);
    } else {
        int value1 = MFSKnapsack(dp, values, weights, i - 1, j);
        int value2 = MFSKnapsack(dp, values, weights, i - 1, j - weights[i]) + values[i];
        value = max(value1, value2);
    }
    dp[i][j] = value;
    return value;
}

void method2(const vector<int> &values, const vector<int> &weights, int capacity)
{
    // 声明dp table
    vector<vector<int>> dp(values.size(), vector<int>(capacity + 1, -1));
    cout << MFSKnapsack(dp, values, weights, values.size() - 1, capacity) << endl;
    // 输出一个最优解
    vector<bool> bitmap(values.size(), false);
    int i = values.size() - 1, j = capacity;
    while (i >= 1) {
        if (dp[i][j] != dp[i - 1][j]) {
            bitmap[i] = true;
            j -= weights[i];
        }
        i--;
    }
    // last one check
    if(dp[i][j] != 0){
        bitmap[i] = true;
    }
    cout << "one solution:[";
    for (int i = 0; i < bitmap.size(); i++) {
        if (bitmap[i]) cout << i + 1 << "(" << values[i] << ")" << ",";
    }
    cout << "]" << endl;
}


int main()
{
    vector<int> values = {12, 10, 20, 15};
    vector<int> weights = {2, 1, 3, 2};
//    method1(values, weights, 5);
    method2(values, weights, 5);
    return 0;
}
