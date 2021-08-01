//
// Created by Raven on 2021/8/1.
//
class Solution {
private:
  bool inited{false};
  unsigned long long dp[11];

private:
  void init() {
    if (inited)
      return;
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 11; i++) {
      dp[i] = 10 * dp[i - 1] + pow10(i - 1);
    }
  }
  
  int countDigitLen(int n, int *first_num) {
    int len = 0;
    while (n) {
      *first_num = n;
      n /= 10;
      len++;
    }
    return len;
  }
  
  int pow10(int n) {
    int base = 1;
    for (int i = 0; i < n; i++) {
      base *= 10;
    }
    return base;
  }
  
  int calc(int num) {
    int leading_digit = 0;
    int len = countDigitLen(num, &leading_digit);
    if (len == 0)
      return 0;
    int remain_num = num - leading_digit * pow10(len - 1);
    int cnt = 0;
    cnt += dp[len - 1] * leading_digit;
    if (leading_digit == 1) {
      cnt += 1 + remain_num;
    } else {
      cnt += pow10(len - 1);
    }
    return cnt + calc(remain_num);
  }

public:
  int countDigitOne(int n) {
    init();
    return calc(n);
  }
  
};
