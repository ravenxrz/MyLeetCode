
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
   public:
    int rand10() {
        while (true) {
            int a = rand7();
            int b = rand7();

            int target = (a - 1) * 7 + b;  // [1,49] 等概率的数字
            if (target <= 40)
                return target % 10 + 1;

            a = target - 40;           // rand9
			b = rand7();
            target = (a - 1) * 7 + b;  // [1,63] 等概率数字
            if (target <= 60)
                return target % 10 + 1;

            a = target - 60;           // rand3
			b = rand7();
            target = (a - 1) * 7 + b;  // [1,21] 等概率数字
            if (target <= 20)
                return target % 10 + 1;
        }
		return 0;
    }
};
