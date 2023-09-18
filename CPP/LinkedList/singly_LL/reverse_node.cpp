// Reversing a singly Linked List
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

void insertNode(Node* &head, int value)
{
    Node* newnode = new Node(value);
    newnode->next = NULL;
    if(head = NULL) {head = newnode; return;}
    Node* temp = head;
    while(temp->next != NULL)
    temp = temp->next;
    temp->next = newnode;
    return;
}

void reverseNode(Node* head)
{
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
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
    cout << "Enter the number of elements: ";
    cin >> n;
    int value;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> value;
        insertNode(head, value);
    }
    cout << "Original Linked List: ";print_LL(head);
    reverseNode(head);
    cout << endl << "After reversing: ";
    print_LL(head);

}