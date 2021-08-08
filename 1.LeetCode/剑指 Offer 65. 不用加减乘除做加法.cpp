class Solution {
   public:
    int add(int a, int b) {
        int tmp_sum = 0;
        int carray = 0;
        do {
            tmp_sum = a ^ b;
            carray = static_cast<unsigned int>(a & b) << 1;
            a = tmp_sum;
            b = carray;
        } while (carray);
        return a;
    }
};