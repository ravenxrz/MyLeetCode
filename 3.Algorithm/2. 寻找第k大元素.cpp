/**
 * 寻找数组中第k小元素
 */
#include <bits/stdc++.h>

using namespace std;

/**
 * 按照快排的方式进行分区, 返回分区pivot所在位置
 * @param vals
 * @param start
 * @param end
 * @return
 */
int partition(vector<int> &vals, int start, int end)
{
    assert(start <= end);
    int pivot = vals[start];
    int i = start, j = end;
    while (i < j) {
        while (j > i && vals[j] >= pivot) --j;
        vals[i] = vals[j];
        while (i < j && vals[i] <= pivot) ++i;
        vals[j] = vals[i];
    }
    vals[j] = pivot;        // 可以忽略本行
    return j;
}


/**
 * 找到第k大的元素， k从0开始编号
 * @param vals
 * @param start
 * @param end
 * @param k
 * @return
 */
int quickSelect(vector<int> &vals, int start, int end, int k)
{
    assert(k >= 0 && start <= end);
    int s = ::partition(vals, start, end);
    if (s == k) {
        return vals[s];
    } else if (s > k) {
        return quickSelect(vals, start, s - 1, k);
    } else {  // s < k
        return quickSelect(vals, s + 1, end, k);    // 注意这里传参依然是传递的k，和伪代码有所不同
    }
}


int main()
{
    vector<int> vals{4,1,10,8,7,12,9 ,2,15};
    cout << quickSelect(vals,0,vals.size()-1,7);
    return 0;
}
