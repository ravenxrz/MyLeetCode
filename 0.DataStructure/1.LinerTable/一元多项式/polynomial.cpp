/**
 * Created by raven on 2020/9/9.
 *
 */
#include "../链式线性表/dlink_list.cpp"

typedef struct {
    double coef;
    int expn;
} polynomial_node;

class polynomial {
public:
    void create();
    
    polynomial add(const polynomial &other);
    
    void print_polynomial();

private:
    dlinklist<polynomial_node> poly;
};


void polynomial::print_polynomial()
{
    polynomial_node node;
    for (size_t i = 1; i <= poly.length() - 1; i++) {
        poly.peek(i, node);
        std::cout << node.coef << "x^" << node.expn << "+";
    }
    poly.peek(poly.length(), node);
    std::cout << node.coef << "x^" << node.expn << "\n";
}

polynomial polynomial::add(const polynomial &other)
{
    polynomial result;
    const polynomial *pa = this;
    const polynomial *pb = &other;
    int i = 1, j = 1;
    polynomial_node temp1, temp2;
    
    if (poly.length() < other.poly.length()) {
        pa = &other;
        pb = this;
    }
    
    /* add */
    while (i <= pa->poly.length() && j <= pb->poly.length()) {
        pa->poly.peek(i, temp1);
        pb->poly.peek(j, temp2);
        if (temp1.expn < temp2.expn) {
            i++;
            result.poly.push_back(temp1);
        } else if (temp1.expn > temp2.expn) {
            j++;
            result.poly.push_back(temp2);
        } else {      /* temp1.expn = temp2.expn */
            polynomial_node new_node; 
            new_node.coef = temp1.coef + temp2.coef;
            new_node.expn = temp1.expn;
            if (new_node.coef != 0) {
                result.poly.push_back(new_node);
            }
            i++;
            j++;
        }
    }
    
    /* remain node */
    while (i <= pa->poly.length()) {
        pa->poly.peek(i, temp1);
        result.poly.push_back(temp1);
        i++;
    }
    
    while (j <= pb->poly.length()) {
        pb->poly.peek(j, temp2);
        result.poly.push_back(temp2);
        j++;
    }
    return result;
}

void polynomial::create()
{
    polynomial_node node;
    /* create */
    while (std::cin >> node.coef && std::cin >> node.expn) {
//        if (node.coef == -1 && node.expn == -1) break;
        poly.push_back(node);
    }
}




