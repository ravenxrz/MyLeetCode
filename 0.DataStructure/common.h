/**
 * Created by raven on 2020/9/8.
 * common use for data structure book
 */

#ifndef MYLEETCODE_COMMON_H
#define MYLEETCODE_COMMON_H

#include <iostream>
#include <cstdlib>
#include <cstring>

/* define some status code */
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW   -2

/* 状态码 */
typedef int Status;

template<typename Iter>
void print_container(Iter in,Iter out)
{
    while(in != out){
        std::cout << *in << " ";
        in++;
    }
    std::cout << "\n";
}


#endif //MYLEETCODE_COMMON_H
