//
// Created by a2855 on 2020/11/17.
// 排序中会用到的通用函数
//

#ifndef MYLEETCODE_COMMON_H
#define MYLEETCODE_COMMON_H

#include <vector>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

template <typename T>
class Sorter{
public:
    virtual ~Sorter() {

    }

    void sort(std::vector<T> &nums){
        auto before = clock();
        _sort(nums);
        auto now = clock();
        std::cout << "time elapsed: " << (double)(now-before)/CLOCKS_PER_SEC << std::endl;
    }
private:
     virtual void _sort(std::vector<T> &nums){
        std::sort(nums.begin(),nums.end());
    }
};

/* 生成[start,end]之间的n个随机数 */
template <typename T>
std::vector<T> generateRandomNumbers(size_t n, int start=0, int end=100){
    assert(n > 0);
    std::vector<T> nums;
    srand((unsigned)time(0));
    for(size_t i = 0;i < n;i++){
        double rnum = (double)rand() / RAND_MAX *(end- start) + start; // [0,1]
        nums.push_back((T)rnum);
    }
    return nums;
}

template <typename T>
void printNums(const std::vector<T>& nums){
    for(auto &val : nums){
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

#endif //MYLEETCODE_COMMON_H
