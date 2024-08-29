// Problem Link:- https://www.geeksforgeeks.org/problems/find-length-of-loop/1
// TO find the length of loop in linked list, if no loop return 0;
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
bool isCyclic(Node* &head) {
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            head = slow;
            return true;
        }
    }
    return false;
}
int countNodesInLoop(Node* head) {
    if(!head)
        return 0;
    Node* temp = head;
    if(isCyclic(temp)) {
        Node* temp2 = temp->next;
        int count = 1;
        while(temp != temp2) {
            count++;
            temp2 = temp2->next;
        }
        return count;
    }
    else 
        return 0;
}
int main() {
    int n, val, pos;
    cout << "Enter number of elements in LL: ";
    cin >> n;
    cout << "Enter elements: ";
    cin >> val;
    Node* head = new Node(val);
    Node* tail = head;
    for(int i=1; i<n; i++) {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    cout << "Enter 1based position of next pointer of the last node:  "; 
    cin >> pos;
    if(pos) {
        int len = 1;
        Node* temp = head;
        while(len != pos) {
            temp = temp->next;
            len++;
        }
        tail->next = temp;
    }
    else 
        tail->next = NULL;
    cout << "Number of nodes in loop: " << countNodesInLoop(head);
}