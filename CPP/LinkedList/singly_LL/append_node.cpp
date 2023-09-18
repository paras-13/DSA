// Appending a node at any position in linked list
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int x)
    {
        next = NULL;
        data = x;
    }
};

void append_node(Node* &head, int val, int pos)
{
    Node* newnode = new Node(val);
    Node* temp = head;
    if(pos == 1)        // Appending at first position
    {
        newnode->next = head;
        head = newnode;
        return;
    }
    for(int i=0; i<pos-2; i++)
    temp = temp->next;
    newnode->next = temp->next;
    temp->next = newnode;
}

void print(Node* head)
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
    Node* n1 = new Node(15);
    Node* n2 = new Node(20);
    Node* n3 = new Node(22);
    Node* n4 = new Node(30);
    Node* n5 = new Node(55);
    Node* n6 = new Node(60);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = n6;
    Node* head = n1;
    int n, pos;
    cout << "Original linked list: ";print(head);
    cout << endl << "Enter a value which you want to append: ";
    cin >> n;
    cout << "Enter position where you want to append: ";
    cin >> pos;
    append_node(head, n, pos);
    print(head); 
}
