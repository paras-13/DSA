// Adding node at the ending of Linked list
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

void insert_node_at_last(Node* &head, int value)
{
    Node* newnode = new Node(value);
    Node* temp = head;
    newnode->next = NULL;
    if(head == NULL){
        newnode->prev = NULL;
        head = newnode; return;
    }
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    return;
}

void print_LL(Node* head)
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
    cout << "Number of elements to enter: ";cin >> n;
    int value;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
    cin >> value;
    insert_node_at_last(head, value);
    }
    print_LL(head);
    cout << endl << "Head pointing to: "<<head->data;
}