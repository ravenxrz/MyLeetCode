#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int divide(int a, int b) {
		if(a == INT_MIN && b == -1) return INT_MAX;
		 return a / b; 
	}
};

int main(int argc, const char** argv) {
    Solution sol;
    cout << sol.divide(-2147483648, -2147483648);
    return 0;
}