#include <iostream>
#include "avl.cpp"
#include <vector>
using namespace std;

int main()
{
    Node *root = createNode(20);
    root = Insert(root, 10);
    root = Insert(root, 40);
    root = Insert(root, 50);
    root = Insert(root, 70);

    print2D(root);
    cout << endl
         << endl
         << endl;
    root = Remove(root, 20);
    root = Remove(root, 10);

    print2D(root);

    RemoveMinInLevel(root, 1);
    print2D(root);

    system("pause");
    return 0;
}
