/**
 * Created by raven on 2020/9/10.
 * hanoi问题，递归求解
 * 假设有 x，y，z三个柱子，
 * x柱有n个圆盘，如何将n个圆盘移动到z柱
 * 要求，圆盘小的不能再圆盘大的下面
 *
 * 求解：移动n个盘，等于将n-1个盘移动到y柱，然后将第
 * n个盘移动到z柱，最后再将n-1个盘移动到z柱
 *
 * 设F(n)为将n个盘从一个柱移动到另一个柱至少需要移动的次数，则
 * F(n) = F(n-1) + 1 + F(n-1)
 * 第一个F(n-1)为从x将n-1个盘移动到y
 * 1代表，将第n个盘从x移动到z
 * 第二F(n-1)为从y将n-1个盘移动z
 * 根据迭代法，最后可得到通式:
 * F(n) = 2^n -1
 */
#include <iostream>
#include <cstdio>

using namespace std;

static int counter = 0;

void move(int n, int from, int to)
{
    printf("move %d from cylinder %d to cylinder %d\n", n, from, to);
    counter++;
}


/**
 *
 * @param n 还有多少个盘
 * @param from
 * @param to
 * @param aux
 * @return
 */
void hanoi(int n, int from, int to, int aux)
{
    if (n == 1) {
        move(1, from, to);
    } else {
        hanoi(n - 1, from, aux, to);
        move(n, from, to);
        hanoi(n - 1, aux, to, from);
    }
}


int main()
{
    int x = 1, y = 2, z = 3, n = 4;
    hanoi(n, x, z, y);
    cout << counter << endl;
    return 0;
}

