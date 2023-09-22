// Write a function that counts the number of times a given int occurs in a Linked List
#include <iostream>
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

void insertNode(Node** head, int value)
{
    Node* newnode = new Node(value);
    newnode->next = *head;
    *head = newnode;
}

int findFrequency(Node* head, int num)
{
    int count=0;
    while(head!=NULL)
    {
    if(head->data == num) count++;
    head = head->next;
    }
    return count;
}

int main()
{
    Node* head = NULL;
    int n, val, num, count;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        insertNode(&head, val);
    }
    cout << "Enter element to count: ";
    cin >> num;
    count = findFrequency(head, num);
    if(count) cout <<"Count: "<<count;
    else cout << "Element not found!. Count: "<<count;
}