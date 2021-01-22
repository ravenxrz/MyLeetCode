//
// Created by Raven on 2021/1/22.
//
#include <algorithm>
#include <iostream>

using namespace std;

bool equal(double value1, double value2)
{
    return abs(value1 - value2) < 1e-20;
}

int main()
{
    double v1 = 1.234567891011121311111111111111111111111111111111111111111111111111111111111f;
    double v2 = 1.234567891011121311111111111111111111111111111111111111111111111111111111112f;
    cout << equal(v1, v2) << endl;
    cout << (v1 == v2) << endl;
    return 0;
}
