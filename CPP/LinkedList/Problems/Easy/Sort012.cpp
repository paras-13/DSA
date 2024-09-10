// Problem to sort Linked list with 0, 1, 2 elements:
// In time O(n) and space O(1);
// GFG link -- > https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/0
#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};
Node* insertNode(Node* head, int n) {   // Function for Creating Linked List
    int val;
    Node* temp = NULL;
    for(int i=0; i<n; i++) {
        cin >> val;
        if(!head)  {
            head = new Node(val);
            temp = head;
        }
        else {
            Node* newNode = new Node(val);
            temp->next = newNode;
            temp = newNode;
        }
    }
    temp->next = NULL;
    return head;
}
// Sorting function :- Time-O(n), Space- O(1)
Node* sortLL(Node* head) {
    if(!head)
        return head;
    Node* one = NULL;
    Node* two = NULL;
    Node* zero = NULL;
    Node* f0 = NULL;
    Node* f1 = NULL;
    Node* f2 = NULL;
    Node* curr = head;

    while(curr) {
        if(curr->data == 0) {
            if(!zero) {
                zero = curr;
                f0 = curr;
            }
            else {
                zero->next = curr;
                zero = curr;
            }
        }
        else if(curr->data == 1) {
            if(!one) {
                one = curr;
                f1 = curr;
            }
            else {
                one->next = curr;
                one = curr;
            }
        }
        else {
            if(!two) {
                two = curr;
                f2 = curr;
            }
            else {
                two->next = curr;
                two = curr;
            }
        }
        curr = curr->next;
    }
    if(zero)  // if pointer is not NULL
        zero->next = (f1) ? f1 : f2;
    if(one)
        one->next = f2;
    if(two)
        two->next = NULL;
    if(f0)
        head = f0;
    else if(f1)
        head = f1;
    else if(f2)
        head = f2;
    return head;
}
void printLL(Node* head) {
    if(!head) return;
    cout << head->data << " ";
    printLL(head->next);
}
int main() {
    Node* head = NULL;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    head = insertNode(head, n);
    head = sortLL(head);
    printLL(head);
}