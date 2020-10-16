//
// Created by a2855 on 2020/10/16.
// 二进制加法
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string binary_add(string num1,  string num2)
{
    // 保证num1的长度是大于等于num2的
    if(num1.size() < num2.size()){
        num1.swap(num2);
    }

    // 可做优化，从末尾开始加，为了方便理解，这里做逆序操作
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());

    string r_ret(num1.size()+1,' ');   // 反序结果
    short carry = 0; // 进位
    int i;
    // 公共位
    for(i = 0;i<num2.size();i++){
        short n1 = num1.at(i) - '0';
        short n2 = num2.at(i) - '0';
        short ans = n1 + n2 + carry;
        carry = ans /2;
        r_ret[i] = (ans % 2) + '0';
    }
    // n1 比 n2长的位
    for(i = num2.size();i<num1.size();i++){
        short n1 = num1.at(i) - '0';
        short ans = n1 +carry;
        carry = ans /2;
        r_ret[i] = (ans % 2) + '0';
    }
    // 最高位进位
    r_ret[i] = carry + '0';

    reverse(r_ret.begin(),r_ret.end());

    // 如果没有进位，去掉最高0
    if(carry == 0){
        return r_ret.substr(1,r_ret.size()-1);
    }
    return r_ret;
}


int main()
{
    cout << binary_add("101100","001010101011001111010101010101101010101111");

    return 0;
}