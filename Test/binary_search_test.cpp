//
// Created by Raven on 2021/3/14.
//

#include "data_generator.h"
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a < b;
}


int main()
{
    auto data = DataGenerator::generate(1000, 1, 10000);
    sort(data.begin(), data.end(), compare);
    printData(data);
    return 0;
}
