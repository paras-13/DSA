// Program to check whether a linked list is palindrome or not.
// Code --> 
#include <iostream>
using namespace std;
class Node
{
    public:
    char data;
    Node* next;
    Node* prev;
    Node(char x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void insertNode(Node* &head, char val)
{
    Node* newnode = new Node(val);
    newnode->next = head;
    newnode->prev = NULL;
    if(head!=NULL)
    head->prev = newnode;
    head = newnode;
}

int checkPallindrome(Node* head, int n)
{
    Node* temp = head;
    Node* tail = NULL;
    while(temp->next!= NULL) temp=temp->next;
    tail = temp;
    int ct=0;
    while(ct!=n/2)
    {
        if(head->data == tail->data) {head=head->next; tail=tail->prev;}
        else return 0;
        ct++;
    }
    return 1;
}

int main()
{
    Node* head = NULL;
    int n, res;
    char val;
    cout << "Enter number of characters to enter: "; cin >> n;
    cout << "Enter characters: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        insertNode(head, val);
    }
    res = checkPallindrome(head, n);
    if(res) cout << "Given string is palindrome"<<endl;
    else cout << "Given string is not a palindrome" << endl;
}
