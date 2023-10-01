// Rotating a Linked list:
// For a singly Linked List;
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void insertNode(Node **head, int val)
{
    Node *newnode = new Node(val);
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void rotateNode(Node **head, int key)
{
    Node *temp = *head;
    int ct = 0;
    if(key == 0) return;
    while (key--)
    {
        while (temp->next->next != NULL)
            temp = temp->next;
        Node *t = temp->next;
        temp->next = NULL;
        temp = t;
        temp->next = *head;
        *head = temp;
    }
}

void printLL(Node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    int n, val, key;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertNode(&head, val);
    }
    cout << "Enter rotation key: "; cin >> key;
    cout << "Before rotation: "; printLL(head);
    rotateNode(&head, key);
    cout << endl << "After rotation: "; printLL(head);
    return 0;
}