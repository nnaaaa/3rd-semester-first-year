#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *pNext;
    Node *pPrev;
};

struct d_List
{
    Node *pHead;
    Node *pTail;
};

Node *createNode(int data)
{
    Node *pNode = new Node;
    pNode->key = data;
    pNode->pNext = NULL;
    pNode->pPrev = NULL;
    return pNode;
}

d_List *createList(Node *p_node)
{
    d_List *List = new d_List;
    List->pHead = List->pTail = p_node;
    return List;
}

bool addHead(d_List *&L, int data)
{
    Node *pNode = createNode(data);
    pNode->pNext = L->pHead;
    pNode->pPrev = NULL;
    L->pHead->pPrev = pNode;
    L->pHead = pNode;
}
bool addTail(d_List *&L, int data)
{
    Node *newNode = createNode(data);
    if (!newNode)
        return 0;

    if (L && L->pTail)
    {
        L->pTail->pNext = newNode;
        newNode->pPrev = L->pTail;
        L->pTail = newNode;
        return 1;
    }
    L = createList(newNode);
    return 1;
}
void removeHead(d_List *&L)
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
    pNode->pNext->pPrev = NULL;
    delete pNode;
}
void removeTail(d_List *&L)
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
    Node *pNode = L->pTail;
    L->pTail = L->pTail->pPrev;
    L->pTail->pNext = NULL;
    delete pNode;
}
void removeAll(d_List *&L)
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
void removeBefore(d_List *&L, int val)
{
    if (L->pHead == NULL)
    {
        cout << "Is empty. \n";
        return;
    }
    if (L->pHead == L->pTail || L->pHead->key == val)
    {
        cout << "Can't delete before the value. \n";
        return;
    }
    if (L->pHead->pNext->key == val)
    {
        removeHead(L);
        return;
    }

    Node *pNode = L->pHead;
    while (pNode->key != val)
    {
        pNode = pNode->pNext;
        if (pNode->pNext == NULL)
        {
            cout << "Can't find value";
            return;
        }
    }
    Node *temp = pNode->pPrev;
    Node *pre = pNode->pPrev->pPrev;
    pre->pNext = pNode;
    pNode->pPrev = pre;
    delete temp;
}
void removeAfter(d_List *&L, int val)
{
    if (L->pHead == NULL)
    {
        cout << "Is empty. \n";
        return;
    }
    if (L->pHead == L->pTail || L->pTail->key == val)
    {
        cout << "Can't remove after value. \n";
        return;
    }
    if (L->pHead->pNext == L->pTail && L->pHead->key == val)
    {
        Node *pNode = L->pTail;
        L->pTail = L->pHead;
        L->pHead->pNext == NULL;
        delete pNode;
        return;
    }
    Node *pNode = L->pHead;
    while (pNode->key != val)
    {
        if (pNode->pNext == NULL)
        {
            cout << "Can't find value. \n";
            return;
        }
        pNode = pNode->pNext;
    }
    Node *temp = pNode->pNext;
    Node *temp2 = pNode->pNext->pNext;
    if (temp2 != NULL)
    {
        pNode->pNext = temp2;
        temp2->pPrev = pNode;
        delete temp;
    }
    else
    {
        pNode->pNext = temp2;
        delete temp;
    }
}
bool addPos(d_List *&L, int data, int pos)
{
    Node *pNode = createNode(data);
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
            Node *previous = pCur->pNext;
            pNode->pNext = previous;
            pNode->pPrev = pCur;
            previous->pPrev = pNode;
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
void RemovePos(d_List *&L, int pos)
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
    while (pCur->pNext != NULL)
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
            Node *temp = pCur->pNext->pNext;
            if (temp != NULL)
            {
                pCur->pNext = temp;
                temp->pPrev = pCur;
            }
            else
                pCur->pNext = temp;
            delete pNode;
            return;
        }
        pCur = pCur->pNext;
    }
}
bool addBefore(d_List *&L, int data, int val)
{
    if (L->pHead == NULL)
    {
        return 0;
    }
    if (L->pHead->key == val)
    {
        addHead(L, data);
        return 1;
    }
    Node *temp = new Node;
    if (temp == NULL)
    {
        return 0;
    }
    temp->key = data;
    Node *pNode = L->pHead;
    while (pNode->key != val)
    {
        pNode = pNode->pNext;
        if (pNode == L->pTail && L->pTail->key != val)
        {
            return 0;
        }
    }
    Node *previous = pNode->pPrev;
    temp->pNext = pNode;
    temp->pPrev = previous;
    previous->pNext = temp;
    pNode->pPrev = temp;
    return 1;
}
bool addAfter(d_List *&L, int data, int val)
{
    if (L->pHead == NULL)
        return 0;
    Node *pNode = L->pHead;
    while (pNode != NULL && pNode->key != val)
        pNode = pNode->pNext;
    if (pNode == NULL && pNode->key != val)
        return 0;
    Node *temp = createNode(data);
    Node *previous = pNode->pNext;
    if (previous != NULL)
    {
        temp->pNext = previous;
        previous->pPrev = temp;
        pNode->pNext = temp;
        temp->pPrev = pNode;
    }
    else
    {
        temp->pNext = previous;
        pNode->pNext = temp;
        temp->pPrev = pNode;
    }
    return 1;
}
int countElements(d_List *L)
{
    if (L->pHead == NULL)
        return 0;
    int count = 1;
    Node *pNode = L->pHead;
    while (pNode->pNext != NULL)
    {
        count++;
        pNode = pNode->pNext;
    }
    return count;
}
void reverseList(Node *&head)
{
    Node *temp = NULL;
    Node *current = head;
    while (current != NULL)
    {
        temp = current->pPrev;
        current->pPrev = current->pNext;
        current->pNext = temp;
        current = current->pPrev;
    }

    if (temp != NULL)
        head = temp->pPrev;
}
bool removeElement(Node *&head, int key)
{
    if (!head)
        return 0;
    if (head->key == key)
    {
        Node *tempNext = head->pNext;
        Node *tempPre = head->pPrev;
        delete head;
        if (tempNext)
            tempNext->pPrev = tempPre;
        if (tempPre)
            tempPre->pNext = tempNext;
        head = tempNext;
        return 1;
    }
    else
        return removeElement(head->pNext, key);
}
void removeDuplicate(d_List *&L)
{
    Node *cur = L->pHead;
    while (cur)
    {
        Node *node = cur->pNext;
        while (node)
        {
            if (cur->key == node->key)
                removeElement(node, node->key);
            else
                node = node->pNext;
        }
        cur = cur->pNext;
    }
}

void printList(d_List *L)
{
    if (L->pHead == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    Node *pNode = L->pHead;
    while (pNode->pNext != NULL)
    {
        cout << pNode->key << "<->";
        pNode = pNode->pNext;
    }
    cout << pNode->key;
    cout << endl;
}

int main()
{
    d_List *List = createList(createNode(1));
    addTail(List, 1);
    addTail(List, 4);
    addTail(List, 10);
    addTail(List, 10);
    removeDuplicate(List);
    printList(List);
    system("pause");
    return 0;
}