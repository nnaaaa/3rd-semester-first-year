#include <iostream>
using namespace std;
#include <queue>
#include <climits>
struct Node
{
    int height;
    int key;
    Node *left;
    Node *right;
};
#define COUNT 20
void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);

    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->key << "\n";

    print2DUtil(root->left, space);
}
void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

// utils
int Height(Node *root)
{
    if (!root)
        return 0;
    int lheight = Height(root->left);
    int rheight = Height(root->right);
    if (lheight > rheight)
        return lheight + 1;
    else
        return rheight + 1;
}
int Level(Node *root, Node *p)
{
    if (!root || !p)
        return 0;
    if (root == p)
        return 1;
    if (p->key < root->key)
        return 1 + Level(root->left, p);
    if (p->key > root->key)
        return 1 + Level(root->right, p);
}
void LevelOrder(Node *root)
{
    queue<Node *> r;
    r.push(root);
    while (!r.empty())
    {
        cout << r.front()->key << ":" << Level(root, r.front()) << " ";
        if (r.front()->left)
            r.push(r.front()->left);
        if (r.front()->right)
            r.push(r.front()->right);
        r.pop();
    }
}
Node *createNode(int x)
{
    Node *n = new Node;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    n->key = x;
    return n;
}
Node *leftRotate(Node *&root)
{
    Node *right = root->right;
    Node *rightLeft = right->left;
    right->left = root;
    root->right = rightLeft;

    right->height = Height(right);
    root->height = Height(root);

    return right;
}
Node *rightRotate(Node *&root)
{
    Node *left = root->left;
    Node *leftRight = left->right;
    left->right = root;
    root->left = leftRight;

    left->height = Height(left);
    root->height = Height(root);

    return left;
}
int checkBalance(Node *root)
{
    int left = Height(root->left);
    int right = Height(root->right);
    return left - right;
}
Node *balance(Node *root, int x)
{
    int balance = checkBalance(root);

    // Left Left Case
    if (balance > 1 && checkBalance(root->left) >= 0)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && checkBalance(root->right) <= 0)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && checkBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && checkBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
Node *Insert(Node *&root, int x)
{
    if (!root)
        return createNode(x);

    if (x < root->key)
        root->left = Insert(root->left, x);
    else if (x > root->key)
        root->right = Insert(root->right, x);
    else
        return root;

    root->height = Height(root);

    return balance(root, x);
}
Node *Remove(Node *&root, int x)
{
    if (root == NULL)
        return root;

    if (x < root->key)
        root->left = Remove(root->left, x);
    else if (x > root->key)
        root->right = Remove(root->right, x);
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            root = NULL;
        }
        else if (root->left && !root->right)
        {
            root->key = root->left->key;
            delete root->left;
            root->left = NULL;
        }
        else if (!root->left && root->right)
        {
            root->key = root->right->key;
            delete root->right;
            root->right = NULL;
        }
        else if (root->left && root->right)
        {
            Node *cur = root->right;
            while (cur->left)
                cur = cur->left;
            root->key = cur->key;
            root->right = Remove(root->right, cur->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = Height(root);

    return balance(root, root->key);
}
bool isAVL(Node* pRoot){
    if (pRoot == NULL)
    {
        return true;
    }
    int heigh = Height(pRoot->left) - Height(pRoot->right);
    if (heigh > 1 || heigh < -1)
    {
        return false;
    }
    return isAVL(pRoot->left) && isAVL(pRoot->right);
}


// more
Node *RemoveMinInLevel(Node *&root, int level)
{
    queue<Node *> q;
    vector<Node *> v;
    q.push(root);
    while (!q.empty())
    {
        if (Level(root, q.front()) == level)
            v.push_back(q.front());
        if (q.front()->left)
            q.push(q.front()->left);
        if (q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }
    int min = INT_MAX;
    int idx = 0;
    for (int i = 0; i < v.size(); ++i)
        if (min < v[i]->key)
        {
            idx = i;
            min = v[i]->key;
        }
    root = Remove(root, v[idx]->key);
    return root;
}



int main()
{
    Node *root = createNode(20);
    root = Insert(root, 10);
    root = Insert(root, 40);
    root = Insert(root, 50);
    root = Insert(root, 70);

    LevelOrder(root);
    cout << endl;
    RemoveMinInLevel(root, 2);
    LevelOrder(root);

    system("pause");
    return 0;
}