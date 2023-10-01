// Delete node in a doubly Linked List
// Updating both head and previous pointers

#include <iostream>
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

int findpos(Node* temp, int val)
{
    int ct = 1;
    if(temp->data == val) return 1;
    while(temp->data!=val)
    {
        ct++; temp = temp->next;
    }
    return ct;
}
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
    temp=temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    return;
}

void deleteNode(Node **head, int pos)
{
    Node* temp = *head;
    if(pos == 1)
    {
        *head = temp->next;
        return;
    }
    for(int i=0; i<pos-2; i++)
    temp=temp->next;
    temp->next->next->prev = temp;
    temp->next = temp->next->next;
}

void printLL(Node* temp)
{
    while(temp!=NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node* head= NULL;
    int n, val, ch, var;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        insertNode(&head, val);
    }
    cout <<"Enter value or position to delete: "<<endl;
    cout << "1: To enter position to delete" << endl << "2: To enter value to delete" << endl;
    cin >> ch;
    cout << "Original Linked List: "; printLL(head);
    switch(ch)
    {
        case 1: cout << endl <<"Enter position to delete: ";cin >> var; deleteNode(&head, var); break;
        case 2: cout << endl <<"Enter value to delete: "; cin >> var; var = findpos(head, var); deleteNode(&head, var); break;
        default: cout << "Incorrect choice";
    }
    cout << "After deleting: ";printLL(head);
}