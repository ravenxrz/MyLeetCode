//
// Created by Raven on 2021/2/17.
//

#ifndef MYLEETCODE_DATA_GENERATOR_H
#define MYLEETCODE_DATA_GENERATOR_H

#include <vector>
#include <iostream>
#include <ctime>
#include <cassert>

class DataGenerator {
public:
    static std::vector<int> generate(int num, int start, int end)
    {
        assert(num > 0);
        srand(time(NULL));
        std::vector<int> nums(num, 0);
        for (int i = 0; i < num; i++) {
            double factor = (double) (rand()) / RAND_MAX;
            nums[i] = factor * (end - start) + start;
        }
        return nums;
    }
};

// 一般不允许在头文件中实现函数，不过这里只是为了写算法，所以whatever了
void printData(const std::vector<int> &data)
{
    for (auto val : data) {
        std::cout << val << " ";
    }
    std::cout << '\n';
}

#endif //MYLEETCODE_DATA_GENERATOR_H
