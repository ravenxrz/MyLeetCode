/**
 * Created by raven on 2020/9/11.
 */
#include "hstring.cpp"
#include <iostream>
using namespace std;

int main()
{
    hstring str1("hello");
    cout << str1.length() << "\n";
    hstring str2("helle");
    cout << str1.compare(str2) << "\n";
    hstring sub_str1 = str1.substring(0,3);
    cout << sub_str1 << "\n" ;
    hstring con_str = str1.concat(str2);
    cout << con_str;
    return 0;
}

