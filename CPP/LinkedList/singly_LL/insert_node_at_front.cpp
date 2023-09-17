// Inserting node at front of a linked list
#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void insert_node_at_front(Node* &head, int value)
{
    Node* newnode = new Node(value);
    newnode->next = head;
    head = newnode;
}

void print_linked_list(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;
    int n;
    cout << "Enter number of elements to enter in Linked List: ";
    cin >> n;
    int i=0, value;
    cout << "Enter elements: ";
    while(i<n)
    {
        cin >> value;
        insert_node_at_front(head, value);
        i++;
    }
    print_linked_list(head);
    cout << endl << "head is pointing to: " << head->data;
}