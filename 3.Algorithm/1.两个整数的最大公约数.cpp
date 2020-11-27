//
// Created by a2855 on 2020/11/27.
//

/**
 * 欧几里德方法
 * @param m 
 * @param n 
 * @return 
 */
int gcd(int m, int n){
    if(n == 0) return m;
    return gcd(n, m % n);
}

/**
 * 连续整数检测算法
 * @param m
 * @param n
 * @return
 */
int gcd2(int m, int n){
    int t  = min(m,n);
    while(true){
        if(m % t == 0 && n % t == 0){
             return t;
        }
        t--;
    }
}
