//
// Created by Raven on 2020/11/7.
// 本题由 leetcode 96 改编
// 输入：正数n，表示二叉树应该有n个节点
// 输出：可能存在的二叉树的结构个数
//

#include <vector>
#include <iostream>
using namespace std;


vector<int> nums;
/**
 * @param remain 剩余节点数
 * @return
 */
int f(int remain){
    if(remain == 0){
        return 0;
    }
    if(remain == 1){
        return 1;
    }
    if(nums[remain] != -1){
        return nums[remain];
    }
    
    int sum = 0;
    for(int i = 1;i<=remain;i++){
        int sum1 = f(i-1);
        int sum2 = f(remain -i);
        if(sum1 == 0 && sum2 != 0){
            sum += sum2;
        }else if(sum1 != 0 && sum2 == 0){
            sum += sum1;
        }else{
            sum += (sum1 * sum2);
        }
    }
    nums[remain] = sum;
    return sum;
}


int main()
{
    for(int i = 1;i<=100;i++){
        nums.resize(i+1,-1);
        cout << f(i) << endl;
    }
    return 0;
}

