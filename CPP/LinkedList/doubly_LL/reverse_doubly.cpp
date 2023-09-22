// Reversing a doubly linked list
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void insertNode(Node **head, int val)
{
    Node* newnode = new Node(val);
    newnode->next = NULL;
    if(*head == NULL)
    {
        newnode->prev = NULL;
        *head = newnode;
        return;
    }
    Node* temp = *head;
    while(temp->next!=NULL)
    temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
}

void reverseNode(Node** head)
{
    Node* curr = *head;
    Node* temp = NULL;
    while(curr!=NULL)
    {
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;
    curr = curr->prev;
    }
    if(temp!=NULL)
    *head = temp->prev;
}

void print_LL(Node* head)
{
    while(head!=NULL)
    {
        cout << head->data <<" ";
        head = head->next;
    }
}
int main()
{
    Node* head = NULL;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        insertNode(&head, val);
    }
    reverseNode(&head);
    print_LL(head);
}