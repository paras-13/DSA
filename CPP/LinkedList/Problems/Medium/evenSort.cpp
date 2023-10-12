// Linked list program to move all the even numbers in a linked list at front as per serial without making a new Linked List.
// Code -->
#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int x)
    {
        data =x;
        next = NULL;
    }
};

void insertNode(Node* &head, int val)
{
    Node* newnode = new Node(val);
    newnode->next = NULL;
    if(head == NULL) {head = newnode; return;}
    Node* temp = head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next = newnode;
}

void evenSort(Node* &head)
{
    Node* temp = head;
    Node* evenH = NULL;
    Node* evenT = NULL;
    Node* oddH = NULL;
    Node* oddT = NULL;

    if(temp==NULL) return;
    while(temp!=NULL)
    {
        if(temp->data %2 == 0)
        {
            if(evenH == NULL)
            {
                evenH = temp;
                evenT = temp;
            }
            else
            {
                evenT->next = temp;
                evenT = temp;
            }
        }
        else
        {
            if(oddH == NULL)
            {
                oddH = temp;
                oddT = temp;
            }
            else
            {
                oddT->next = temp;
                oddT = temp;
            }
        }
        temp=temp->next;
    }
    if(evenT!=NULL) evenT->next = oddH;
    if(oddT!=NULL) oddT->next=NULL;
    if(evenH==NULL) evenH = oddH;
    head = evenH;
}

void printLL(Node* head)
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
    int n, val;
    cout << "Enter size of Linked list: ";
    cin >> n;
    cout << "Enter elements in LL: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        insertNode(head, val);
    }
    evenSort(head);
    printLL(head);
}