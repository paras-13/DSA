// Sort Linked List using Bubble Sort: 

// Time Complexity :- O(n^2)
// Auxillary Space :- O(1)

#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next = NULL;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void insertNode(Node **head, int val)
{
    Node* newnode = new Node(val);
    newnode->next = *head;
    *head = newnode;
}

Node* swap(Node *ptr1, Node *ptr2)   // Function to swap the pointers
{
    Node* temp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = temp;
    return ptr2;
}
void bubbleSortLL(Node **head, int n)  // Sorting algo
{
    Node **temp;
    int flag;
    for(int i=0; i<n; i++)
    {
        flag = 0;
        temp = head;
        for(int j=0; j<n-i-1; j++)
        {
            Node* ptr1 = *temp;
            Node* ptr2 = ptr1->next;
            if(ptr1->data > ptr2->data)
            {
                *temp = swap(ptr1, ptr2);
                flag = 1;
            }
            temp = &(*temp)->next;
        }
        if(flag!=1) break;   // break condition (optimized)
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
    Node* head = NULL;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        insertNode(&head, val);
    }
    bubbleSortLL(&head, n);
    printLL(head);
    return 0;
}