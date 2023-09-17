// Inserting node at/from end
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

void insert_node_at_end(Node* &head, int value)
{
    Node* newnode = new Node(value);
    newnode->next = NULL;
    
    if(head == NULL) { head = newnode; return; }

    Node* temp = head;
    while(temp->next != NULL)
    temp=temp->next;
    temp->next = newnode;
    return;
}

void print_linked_list(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }
}

int main()
{
    Node* head = NULL;
    int n; cout << "Enter number of elements to enter in Linked List: ";
    cin >> n;
    int i=0, value;
    cout << "Enter elements: ";
    while(i<n)
    {
        cin >> value;
        insert_node_at_end(head, value);
        i++;
    }
    print_linked_list(head);
    cout << endl << "Head pointing to: "<<head->data;
    return 0;
}