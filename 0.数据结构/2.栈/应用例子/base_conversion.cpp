/**
 * Created by raven on 2020/9/9.
 * base conversion
 * 给定任意十进制数，转换为需要的进制数
 */
#include "../顺序栈/sq_stack.cpp"

void convert(int base, int value)
{
    sqstack<int> stack;
    int k = value;
    int temp;
    
    while(k != 0){
        stack.push(k % base);
        k = k / base;
    }
    
    /* print result */
    while(!stack.isempty()){
        stack.pop(temp);
        std::cout << temp << "\n";
    }
}

int main()
{
    convert(4,20);
    return 0;
}


