// Removing duplicate element from a unsorted Linked List: 

#include<iostream>
#include <set>
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

void insertNode(Node **head, int val)
{
    Node *newnode = new Node(val);
    newnode->next = *head;
    *head = newnode;
}

void sortLL(Node** head, int n)
{
    Node** temp1;
    int flag;
    for(int i=0; i<n; i++)
    {
        flag = 0;
        temp1 = head;
        for(int j=0; j<n-i-1; j++)
        {
            Node* k = *temp1; Node* l = k->next;
            if(k->data > l->data)
            {
                flag = 1;
                Node* temp2 = l->next;
                l->next = k;
                k->next = temp2;
                *temp1 = l;
            }
            temp1 = &(*temp1)->next;
        }
        if(flag!=1) break;
    }
}
void removeDuplicate(Node *head)
{
    Node* temp = head;
    while(temp->next!=NULL)
    {
        if(temp->data == temp->next->data)
        temp->next = temp->next->next;
        else temp=temp->next;
    }
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
    Node *head = NULL;
    int n; cout << "Enter number of elements: "; cin >> n;
    int val;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        insertNode(&head, val);
    }
    sortLL(&head, n);
    printLL(head);
    cout << endl;
    removeDuplicate(head);
    printLL(head);
}
