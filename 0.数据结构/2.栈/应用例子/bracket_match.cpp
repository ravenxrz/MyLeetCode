/**
 * Created by raven on 2020/9/9.
 * 括号匹配问题
 */
#include "../顺序栈/sq_stack.cpp"

bool match(const std::string &brackets)
{
    sqstack<char> stack;
    char temp;
    
    for(char bracket : brackets){
        switch(bracket){
            case '[':
            case '(':
                stack.push(bracket);break;
            case ']':
                stack.pop(temp);
                if(temp != '['){
                    return false;
                }
                break;
            case ')':
                stack.pop(temp);
                if(temp != '('){
                   return false;
                }
                break;
            default:
                return false;
        }
    }
    if(!stack.isempty()){
        return false;
    }
    return true;
}

int main()
{
    std::string brackets1{"(([][][])[][](((())))"};
    std::cout << match(brackets1);
    
    std::string brackets2{"[[[]]]((([[[]]])))"};
    std::cout << match(brackets2);
    return 0;
}
