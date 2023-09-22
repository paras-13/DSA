// Deleting a Node in Singly Linked List
// The element can be deleted by providing either its position or directly the element
//  --> This code comprise of both the options...
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

void insertNode(Node **head, int val)
{
    Node* newnode = new Node(val);                  // Enter element at runtime;
    newnode->next = NULL;
    if(*head == NULL){ *head = newnode; return;}
    Node* temp = *head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next = newnode;
}

int findpos(Node *head, int inp)    // To find position of element
{
    int count=1;
    Node* temp = head;
    while(temp->data!=inp){
    temp=temp->next; count++;}
    return count;
}
void deleteNode(Node **head, int input, int flag)
{
    Node* temp = *head;
    int pos;
    if(flag == 1)
    input = findpos(*head, input);
    pos = input;
    if(pos == 1) {*head = temp->next; return;}
    for(int i=0; i<pos-2; i++)
    temp=temp->next;
    temp->next = temp->next->next;
    return;
}

void print_LL(Node* head)
{
    while(head!=NULL)
    {
        cout << head->data <<" ";
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;
    int n, val, ch, inp;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        insertNode(&head, val);
    }
    cout << "Enter choice: "<<endl <<"1: To enter element to delete " << endl << "0: To enter position to delete "<<endl;
    cin >> ch;
    if(ch) cout<<"Enter element to delete: ";
    else cout <<"Enter position: ";
    cin >> inp;
    cout << "Original Linked List: "; print_LL(head);
    deleteNode(&head, inp, ch);
    cout << endl << "After Deletion: "; print_LL(head);

}