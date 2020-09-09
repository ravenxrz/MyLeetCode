/**
 * Created by raven on 2020/9/9.
 */
#include "sq_stack.cpp"

int main()
{
    sqstack<int> stack;
    int temp;
    
    for (size_t i = 0; i < 2000; i++) {
        stack.push(i);
    }
    
    stack.gettop(temp);
    std::cout << temp << "\n";
    
    while(!stack.isempty()){
        stack.pop(temp);
        std::cout << temp << "\n";
    }
    return 0;
}