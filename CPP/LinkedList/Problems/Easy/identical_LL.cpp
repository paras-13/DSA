// To check whether the linked list are identical or not:
/*
To Linked List are identical when they have same data and same the arrangement of data is also same*/
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
    if(head == NULL) {head = newnode; return;}
    Node* temp = head;
    while(temp->next != NULL)
    temp = temp->next;
    temp->next = newnode;
    return;
}

int length(Node* head)
{
    int count;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}
int checkIdentical_LL(Node* head1, Node* head2)
{
    if(length(head1) != length(head2)) return 0;
    int flag = 1;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data != head2->data)
        {   flag = 0;
            break;}
        head1 = head1->next;
        head2 = head2->next;
    }
    return flag;
}
int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    int n1, n2, value;
    cout << "Enter number of elements in LL1: ";
    cin >> n1;
    cout << "Enter elements in 1st LL: ";
    for(int i=0; i<n1; i++)
    {
        cin >> value;
        insertNode(head1, value);
    }
    cout << "Enter number of elements in LL2: ";
    cin >> n2;
    cout << "Enter elements in 2nd LL: ";
    for(int i=0; i<n2; i++)
    {
        cin >> value;
        insertNode(head2, value);
    }
    if(checkIdentical_LL(head1, head2))
    cout << "Both linked list are identical!";
    else 
    cout << "Both Linked List are not identical!";
}