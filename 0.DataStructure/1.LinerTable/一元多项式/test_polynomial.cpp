/**
 * Created by raven on 2020/9/9.
 */
#include "polynomial.cpp"
#include <fstream>

int main()
{
    /* redirect input to a file */
    std::ifstream in("/home/raven/Projects/MyLeetCode/0.DataStructure/1.LinerTable/一元多项式/input.txt");
    std::cin.rdbuf(in.rdbuf());

    polynomial p1;
    p1.create();
    p1.print_polynomial();
    
    polynomial p2;
    p2.create();
    p2.print_polynomial();
    
    polynomial p3 = p1.add(p2);
    p3.print_polynomial();
    
    return 0;
}
