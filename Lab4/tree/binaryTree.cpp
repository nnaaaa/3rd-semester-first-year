#include <iostream>
#include <queue>
#include <math.h>
#include <climits>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
};

//declare
int maxNode(Node *root);
int minNode(Node *root);


//print 2d
#define COUNT 10
void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->key << "\n";

    // Process left child
    print2DUtil(root->left, space);
}
void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void Insert(Node *&root, int x)
{
    if (!root)
        root = createNode(x);
    else
    {
        if (x < root->key)
            Insert(root->left, x);
        if (x > root->key)
            Insert(root->right, x);
    }
}
void NLR(Node *root)
{
    if (!root)
        return;
    cout << root->key << " ";
    NLR(root->left);
    NLR(root->right);
}
void LNR(Node *root)
{
    if (!root)
        return;
    LNR(root->left);
    cout << root->key << " ";
    LNR(root->right);
}
void LRN(Node *root)
{
    if (!root)
        return;
    LRN(root->left);
    LRN(root->right);
    cout << root->key << " ";
}
void LevelOrder(Node *root)
{
    queue<Node *> r;
    r.push(root);
    while (!r.empty())
    {
        cout << r.front()->key << " ";
        if (r.front()->left)
            r.push(r.front()->left);
        if (r.front()->right)
            r.push(r.front()->right);
        r.pop();
    }
}
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
int countNode(Node *root)
{
    if (!root)
        return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}
int sumNode(Node *root)
{
    if (!root)
        return 0;
    return root->key + sumNode(root->left) + sumNode(root->right);
}
Node *Search(Node *root, int x)
{
    if (!root)
        return NULL;
    if (x == root->key)
        return root;
    if (x < root->key)
        return Search(root->left, x);
    if (x > root->key)
        return Search(root->right, x);
}
void Remove(Node *&root, int x)
{
    if (root == NULL)
        return;
    if (x < root->key)
        Remove(root->left, x);
    if (x > root->key)
        Remove(root->right, x);
    if (x == root->key)
    {
        if (!root->left && !root->right)
        {
            delete root;
            root = NULL;
            return;
        }
        else if (root->left && !root->right)
        {
            Node *temp = root->left;
            delete root;
            root = temp;
            return;
        }
        else if (!root->left && root->right)
        {
            Node *temp = root->right;
            delete root;
            root = temp;
            return;
        }
        else if (root->left && root->right)
        {
            Node *cur = root->right;
            while (cur->left)
                cur = cur->left;
            root->key = cur->key;
            Remove(root->right, cur->key);
        }
    }
}
Node *createTree(vector<int> a)
{
    Node *root = NULL;
    for (int i = 0; i < a.size(); ++i)
        Insert(root, a[i]);
    return root;
}
void removeTree(Node *&root)
{
    if (root == NULL)
        return;
    removeTree(root->left);
    removeTree(root->right);
    delete root;
    root = NULL;
}
int heightNode(Node *root, int value)
{
    if (!root)
        return -1;
    if (value == root->key)
        return Height(root);
    if (value < root->key)
        return heightNode(root->left, value);
    if (value > root->key)
        return heightNode(root->right, value);
}
int Level(Node *root, Node *p)
{
    if (!root || !p)
        return 0;
    if (p->key < root->key)
        return 1 + Level(root->left, p);
    if (p->key > root->key)
        return 1 + Level(root->right, p);
    return 1;
}
int countLeaf(Node *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}
int countLess(Node *root, int x)
{
    if (!root)
        return 0;
    if (x == root->key)
        return countNode(root->left);
    else if (x > root->key)
        return countLess(root->right, x) + 1 + countNode(root->left);
    else if (x < root->key)
        return countLess(root->left, x);
}
int countGreater(Node *root, int x)
{
    if (!root)
        return 0;
    if (x == root->key)
        return countNode(root->right);
    else if (x > root->key)
        return countGreater(root->right, x);
    else if (x < root->key)
        return countGreater(root->left, x) + 1 + countNode(root->right);
}
bool isBST(Node *root)
{
    if (!root)
        return true;
    if (root->key > maxNode(root->left) && root->key < minNode(root->right))
        return isBST(root->left) && isBST(root->right);
    return false;
}
bool isFullBST(Node *root)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
    if (root->left && root->right && isBST(root))
        return isFullBST(root->left) && isFullBST(root->right);
    return false;
}

// more
int minNode(Node *root)
{
    if (!root)
        return INT_MAX;
    return min(root->key, min(minNode(root->left), minNode(root->right)));
}
int maxNode(Node *root)
{
    if (!root)
        return INT_MIN;
    return max(root->key, max(maxNode(root->left), maxNode(root->right)));
}
int secondMinNode(Node* pNode,int minValue){
    if(!pNode)
        return INT_MAX;
    int a = pNode->key;
    int b = secondMinNode(pNode->left, minValue);
    int c = secondMinNode(pNode->right,minValue);
    
    if (a <= minValue)
        return b > c ? c : b;
    else{
        if (a > b && b > minValue)
            a = b;
        else if (a > c && c > minValue)
            a = c;
        return a;
    }
}
int findkNthNode(Node* pRoot,int k){
    int min = minNode(pRoot);
    if (k==1)
        return min; 
        
    int secondMin = secondMinNode(pRoot, min);
    while (k > 2){
        secondMin = secondMinNode(pRoot,secondMin); 
        k--;
    }
    return secondMin;
}

int main()
{
    Node *root = createNode(20);
    Insert(root, 10);
    Insert(root, 40);
    Insert(root, 50);
    Insert(root, 70);

    print2D(root);
    cout << endl;
    cout << maxNode(root);
    system("pause");
    return 0;
}
