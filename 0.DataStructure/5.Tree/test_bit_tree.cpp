/**
 * Created by raven on 2020/9/14.
 */
#include "../common.h"
#include "bittree.cpp"

/**
 * TEST example:
 * A B # C # # D # #
 * @return
 */
int main(void)
{
    bittree<char> tree;
    tree.create_pre_order();

    cout << "pre order:";
    tree.preorder_traverse();
    cout << "in order:";
    tree.inorder_traverse();
    cout << "post order:";
    tree.postorder_traverse();

    cout << "tree height:" << tree.height() << "\n";
    return 0;
}

