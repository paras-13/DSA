// To find middle element of a linked List:
// Multiple approaches are their to solve this:

/*
1-> Brute force approach -> In this we will firstly create a linked List. 
                         -> Then stotre the values of linked list in a vector/array.
                         -> Find the middle element
            Time-Complexity:- O[n] (for traversing in vector or array)
            Space-Complexity:- O[n] (for storing in vector or array)

2-> Method 1:-      -> Create a linked list
                    -> Traverse the linked list
                    -> Find the total number of nodes
                    -> Now traverse again upto length/2
                    -> Print the value
            Time-Complexity :- O[n] (As we are traversing upto n nodes)
            Auxiliary-Space :- O[1] 

 3-> Method 2:- 
                    -> Create a linked list, declare two pointers [slow, fast]
                    -> Traverse the linked List using these pointers
                    -> Move one pointer(slow) by one and other pointer(fast) by two
                    -> When the fast pointer will reach at end, the slow pointer will reach at middle
                    -> Print the value using slow pointer.
            Time-Complexity :- O[n] (As we are traversing only once)
            Auxiliary-Space :- O[1]
*/
// Code [includes both method1 and method 2]
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

void insertNode(Node* &head, int val)
{
    Node* newnode = new Node(val);
    newnode->next = NULL;
    if(head == NULL) {head = newnode; return;}
    Node* temp = head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next = newnode;
    return;
}

int length(Node* head)              // Function to find length of Linked List
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}

int method1(Node* head)     // Method 1:- Time-Comp O[n]
{
    int mid, len;
    len = length(head);
    mid = len/2;
    for(int i=0; i<mid; i++)
    head = head->next;
    return head->data;
}

int method2(Node* head)     // Method 2: Time Complexity O[n]
{
    
    return 12;
}

void print_LL(Node* head)
{
    while(head!=NULL)
    {
        cout << head->data <<" ";
        head= head->next;
    }
}

int main()
{
    Node* head = NULL;
    int n, val, i=0;
    cout << "Enter size of linked list: ";
    cin >> n;
    cout << "Enter elements: ";
    while(i!=n)
    {
        cin >> val;
        insertNode(head, val);
        i++;
    }
    cout << "Linked List: ";print_LL(head);
    int ch;
    cout << endl<<"Choose: "<<endl<<"1: To use method1" << endl <<"2: To use method2"<<endl;
    cin >> ch;
    switch(ch)
    {
        case 1:
            cout << "Middle value of linked list is: "<< method1(head);
            break;
        case 2:
            cout << "Middle value of Linked List is: "<< method2(head);
            break;
        default:
            cout <<"Invalid choice";
            break;
    }
}


