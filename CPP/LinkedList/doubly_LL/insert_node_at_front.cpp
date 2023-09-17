// Adding node in a doubly linked list fron front
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

void insert_node_at_front(Node* &head, int value)
{
    Node* newnode = new Node(value);
    newnode->next = head;
    newnode->prev = NULL;
    
    if(head != NULL)        // Condition to point previous pointer in order to make a doubly linked list.
    head->prev = newnode;
    head = newnode;
}

void print_LL(Node* head)   // Printing nodes of doubly linked list
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node* head = NULL;
    int n;
    cout << "Enter number of elements to enter: ";
    cin >> n;

    int val;cout << "Enter elements: ";
    while(n--)
    {
        cin >> val;
        insert_node_at_front(head, val);
    }
    cout << "Printing elements of a doubly linked list: "<<endl;
    print_LL(head);
}