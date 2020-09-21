/**
 * Created by raven on 2020/9/11.
 * kmp算法, 和书上next数组定义不同
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;


/**
 * 计算next数组
 * next[j]的含义为, 与当前j位置上的字符所匹配的，在最大前缀上所对应的位置。
 * 如:
 * abcabc 从0开始编码，第二个c(j=5), 在前缀(第一个abc）中c的位置为2，所以next(5)=2
 *                   第二个b(j=4),在前缀（第一个abc)中b的位置为1, 所以next(4）=1
 * next[j] = :
 * 1. j=0时， =-1
 * 2. 无对应前缀时，=0. 如abc这个串，next(1)=0, 因为b之前只有a
 * 3. 其余情况，=max{k| 0<=k<j, 满足paatern[j]=pattern[next[j]]
 *
 * @param pattern
 * @param next
 * @param j
 * example: abaabc
 */
void get_next(const string &pattern, vector<int> &next) {
    int j = 2;
    int i;
    next[0] = -1;       /* next[0]无效 */
    next[1] = 0;        /* next[1]只能指向第0位 */

    while (j < pattern.length()) {      /* 每次循环计算一个next[j] */
        i = next[j - 1];
        if (pattern[j] == pattern[i + 1]) {
            next[j] = i + 1;
        } else {
            /* 递归地寻找下一个匹配字符 */
            do {
                i = next[i];
            } while (i != -1 && pattern[j] != pattern[i + 1]);
            if (i == -1) {
                next[j] = 0;
            } else {                 /* pattern[j] = pattern[i+1] */
                next[j] = i + 1;
            }
        }
        j++;
    }
}

/**
 * 计算pattern在str中的位置
 * @param str
 * @param pattern
 * @return
 */
int kmp(const string &str, const string &pattern) {
    vector<int> next(pattern.length());
    get_next(pattern, next);

    int i = 0, j = 0;
    /* 找到第一个匹配点 */
    while (str[j] != pattern[i]) {
        i++;
        j++;
    }

    /* kmp */
    while (i != pattern.length() && j < str.length()) {
        if (str[j] == pattern[i]) {
            i++;
            j++;
        } else {
            i = next[i];
            if (i == -1) {      /* 主串移动 */
                i = 0;
                j++;
            }
        }
    }
    if (i == pattern.length()) {
        return j - i ;
    }
    return -1;
}

int main() {
    string pattern("aac");
    string str("aabcaabcaac");
    cout << kmp(str, pattern);
    return 0;
}