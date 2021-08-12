#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
    int data;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

// linkedlist
Node *createNode(int data)
{
    Node *pNode = new Node;
    pNode->data = data;
    pNode->pNext = NULL;
    return pNode;
}
List *createList(Node *pNode)
{
    List *L = new List;
    L->pHead = pNode;
    L->pTail = L->pHead;
    L->pHead->pNext = NULL;
    return L;
}
void printList(List *L)
{
    if (!L->pHead)
    {
        cout << "Is empty. \n";
        return;
    }

    Node *pNode = L->pHead;
    while (pNode->pNext != NULL)
    {
        cout << pNode->data << "->";
        pNode = pNode->pNext;
    }
    cout << pNode->data << endl;
}
Node *addHead(List *&L, int data)
{
    Node *pNode = new Node;
    if (pNode == NULL)
    {
        return 0;
    }

    if (L->pHead == NULL)
    {
        pNode->data = data;
        L->pHead = pNode;
        L->pTail = L->pHead;
        L->pTail->pNext = NULL;
        pNode->pNext = NULL;
        return pNode;
    }
    else
    {
        pNode->data = data;
        pNode->pNext = L->pHead;
        L->pHead = pNode;
        return pNode;
    }
}
Node *addTail(List *&L, int data)
{
    if (L->pHead == NULL)
    {
        Node *pNode = addHead(L, data);
        return pNode;
    }
    Node *pNode = new Node;
    pNode->data = data;
    pNode->pNext = NULL;
    L->pTail->pNext = pNode;
    L->pTail = pNode;
    return pNode;
}
void removeHead(List *&L)
{
    if (L->pHead == NULL)
    {
        return;
    }
    if (L->pHead->pNext == NULL)
    {
        delete L->pHead;
        return;
    }
    Node *pNode = L->pHead;
    L->pHead = L->pHead->pNext;
    delete pNode;
}
void removeTail(List *&L)
{
    if (L->pHead == NULL)
    {
        return;
    }
    if (L->pHead == L->pTail)
    {
        removeHead(L);
        return;
    }
    Node *pNode = L->pHead;
    Node *previous = NULL;
    while (pNode->pNext != NULL)
    {
        previous = pNode;
        pNode = pNode->pNext;
    }
    previous->pNext = NULL;
    L->pTail = previous;
    delete pNode;
}
void removeAll(List *&L)
{
    Node *pNode;
    while (L->pHead != NULL)
    {
        pNode = L->pHead;
        L->pHead = L->pHead->pNext;
        delete pNode;
    }
    L->pHead = NULL;
    L->pTail = NULL;
}
bool removeBefore(Node *&head, int val)
{
    if (!head)
        return 0;

    if (head->pNext && head->pNext->data == val)
    {
        Node *temp = head->pNext;
        delete head;
        head = temp;
        return 1;
    }
    else
        return removeBefore(head->pNext, val);
}
bool removeAfter(Node *&head, int val, bool isDelete = 0)
{
    if (!head)
        return 0;
    if (isDelete && head)
    {
        Node *temp = head->pNext;
        delete head;
        head = temp;
        return 1;
    }
    if (head->data == val)
        return removeAfter(head->pNext, val, 1);
    else
        return removeAfter(head->pNext, val, 0);
}
bool addPos(List *&L, int data, int pos)
{
    Node *pNode = new Node;
    if (pNode == NULL)
    {
        return 0;
    }
    if (pos == 0)
    {
        addHead(L, data);
        return 1;
    }
    if (L->pHead == NULL && pos != 0)
    {
        return 0;
    }
    int length = 0;
    Node *pCur = L->pHead;
    while (pCur->pNext != NULL)
    {
        length++;
        if (pos == length)
        {
            pNode->data = data;
            pNode->pNext = pCur->pNext;
            pCur->pNext = pNode;
            return 1;
        }
        pCur = pCur->pNext;
    }
    if (pos > length + 1)
    {
        cout << "Can't add the pos \n";
        return 0;
    }
    if (pos == length + 1)
    {
        addTail(L, data);
        return 1;
    }
}
void removePos(List *&L, int pos)
{
    if (L->pHead == NULL)
    {
        return;
    }
    if (pos == 0)
    {
        removeHead(L);
        return;
    }
    int length = 0;
    Node *pCur = L->pHead;
    while (pCur != NULL)
    {
        length++;

        if (pos == length)
        {
            if (pCur->pNext == L->pTail)
            {
                removeTail(L);
                return;
            }
            Node *pNode = pCur->pNext;
            pCur->pNext = pCur->pNext->pNext;
            delete pNode;
            return;
        }
        pCur = pCur->pNext;
    }
}
bool addBefore(List *&L, int data, int val)
{
    if (L->pHead == NULL)
    {
        return 0;
    }
    if (L->pHead->data == val)
    {
        addHead(L, data);
        return 1;
    }
    Node *temp = new Node;
    if (temp == NULL)
    {
        return 0;
    }
    temp->data = data;
    Node *pNode = L->pHead;
    Node *previous = NULL;
    while (pNode->data != val)
    {
        previous = pNode;
        pNode = pNode->pNext;
        if (pNode == L->pTail && L->pTail->data != val)
        {
            return 0;
        }
    }
    temp->pNext = pNode;
    previous->pNext = temp;
    return 1;
}
bool addAfter(List *&L, int data, int val)
{
    if (L->pHead == NULL)
    {
        return 0;
    }
    Node *pNode = L->pHead;
    while (pNode != NULL && pNode->data != val)
    {
        pNode = pNode->pNext;
    }
    if (pNode == NULL && pNode->data != val)
    {
        return 0;
    }
    Node *temp = new Node;
    temp->data = data;
    temp->pNext = pNode->pNext;
    pNode->pNext = temp;
    return 1;
}
int countElements(List *L)
{
    if (L->pHead == NULL)
    {
        return 0;
    }

    int count = 1;
    Node *pNode = L->pHead;
    while (pNode->pNext != NULL)
    {
        count++;
        pNode = pNode->pNext;
    }
    return count;
}
List *reverseList(List *L)
{
    List *L2 = new List;
    L2->pHead = NULL;
    L2->pTail = NULL;
    Node *pNode = L->pHead;
    while (pNode != NULL)
    {
        addHead(L2, pNode->data);
        pNode = pNode->pNext;
    }
    return L2;
}
bool removeElement(Node *&head, int key)
{
    if (!head)
        return 0;
    if (head->data == key)
    {
        Node *temp = head->pNext;
        delete head;
        head = temp;
        return 1;
    }
    else
        return removeElement(head->pNext, key);
}
void removeDuplicate(List *&L)
{
    if (L->pHead == NULL)
    {
        return;
    }
    Node *pNode = L->pHead;
    while (pNode != NULL && pNode->pNext != NULL)
    {
        int data = pNode->data;
        Node *pCur = pNode;
        while (pCur->pNext != NULL)
        {
            if (pCur->pNext->data == data)
            {
                Node *a = pCur->pNext;
                pCur->pNext = pCur->pNext->pNext;
                delete a;
            }
            else
            {
                pCur = pCur->pNext;
            }
        }
        pNode = pNode->pNext;
    }
}
void removeNode(Node *&head, Node *element)
{
    if (!head)
        return;
    if (head == element)
    {
        Node *temp = head->pNext;
        delete head;
        head = temp;
    }
    else
        removeNode(head->pNext, element);
}
Node *findMiddle(List *List)
{
    Node *fast = List->pHead;
    Node *slow = List->pHead;
    while (fast && fast->pNext)
    {
        fast = fast->pNext->pNext;
        slow = slow->pNext;
    }
    return slow;
}

// stack
Node *initStack(int key)
{
    Node *n = new Node;
    n->data = key;
    n->pNext = NULL;
    return n;
}
void PushStack(List *&l, int key)
{
    addHead(l, key);
}
void PopStack(List *&l)
{
    removeHead(l);
}
int CountStackElement(List *l)
{
    Node *cur = l->pHead;
    int count = 0;
    while (cur)
    {
        count++;
        cur = cur->pNext;
    }
    return count;
}
bool checkEmptyStack(List *l)
{
    if (!l->pHead)
        return 0;
    return 1;
}

// queue
Node *initQueue(int key)
{
    Node *n = new Node;
    n->data = key;
    n->pNext = NULL;
    return n;
}
void Enqueue(List *&l, int key)
{
    addTail(l, key);
}
int Dequeue(List *&l)
{
    int key = l->pHead->data;
    removeHead(l);
    return key;
}
int CountQueueElement(List *l)
{
    Node *cur = l->pHead;
    int count = 0;
    while (cur)
    {
        count++;
        cur = cur->pNext;
    }
    return count;
}
bool checkEmptyQueue(List *l)
{
    if (!l->pHead)
        return 0;
    return 1;
}


// more
int factorial(int x)
{
    if (x == 1)
        return 1;
    return factorial(x - 1) * x;
}
double sum(Node *head, int x = 1)
{
    if (!head)
        return 0;
    return (pow(head->data, x) / factorial(x)) + sum(head->pNext, x + 1);
}
List *mergeTwoList(List *list1, List *list2)
{
    List *l;
    Node *cur1 = list1->pHead;
    Node *cur2 = list2->pHead;
    if (cur1 && cur2)
    {
        if (cur1->data < cur2->data)
        {
            l = createList(createNode(cur1->data));
            cur1 = cur1->pNext;
        }
        else if (cur1->data > cur2->data)
        {
            l = createList(createNode(cur2->data));
            cur2 = cur2->pNext;
        }
    }
    else if (cur1)
    {
        l = createList(createNode(cur1->data));
        cur1 = cur1->pNext;
    }
    else if (cur2)
    {
        l = createList(createNode(cur2->data));
        cur2 = cur2->pNext;
    }

    while (cur1 || cur2)
    {
        if (cur1 && cur2)
        {
            if (cur1->data < cur2->data)
            {
                addTail(l, cur1->data);
                cur1 = cur1->pNext;
            }
            else
            {
                addTail(l, cur2->data);
                cur2 = cur2->pNext;
            }
        }
        else if (cur1)
        {
            addTail(l, cur1->data);
            cur1 = cur1->pNext;
        }
        else if (cur2)
        {
            addTail(l, cur2->data);
            cur2 = cur2->pNext;
        }
    }
    return l;
}
void sortList(List* &L){
    if (!L->pHead)
        return;
    Node* node = L->pHead;
    while (node)
    {
        Node *cur = node->pNext;
        while (cur){
            if (cur->data < node->data){
                int temp = node->data;
                node->data = cur->data;
                cur->data = temp;
            }
            cur = cur->pNext;
        }
        node = node->pNext;
    }
}



int main()
{
    List *L = createList(createNode(2));
    addTail(L, 3);
    addTail(L, 3);
    addTail(L, 3);
    addTail(L, 10);
    removeElement(L->pHead, 3);
    removeElement(L->pHead, 10);
    removeElement(L->pHead, 1);
    printList(L);
    system("pause");
    return 0;
}
