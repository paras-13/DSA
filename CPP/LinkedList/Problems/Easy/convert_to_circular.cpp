// Ques --> To convert a singly linked list to circular Linked List:
/*
        -> Traverse to the last till NULL
        -> Now point the last to head
*/
#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int x)
    {
        data = x; next = NULL;
    }
};
void insertNode(Node** head, int val)
{
    Node* newnode = new Node(val);
    newnode->next = NULL;
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL)
    temp = temp->next;
    temp->next = newnode;
}

void convertToCircular(Node** head)
{
    if(*head == NULL || *head->next == NULL) return; 
    Node* temp = *head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next = *head;
}

void print_LL(Node* head)
{
    Node* temp = head;
    while(temp->next!=head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node* head = NULL;
    int n; cout << "Enter number of Linked List elements: ";
    cin >> n;
    int val;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        insertNode(&head, val);
    }
    convertToCircular(&head);
    print_LL(head);
}