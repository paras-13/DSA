// Insert Element at the End Of Stack
/* 
? Given a stack S and an integer N, the task is to insert N at the bottom of the stack.
Time: O(N); Space: O(N);
*/

// Naive approach: Using another stack to store elements as temporary store.

// Efficient Approach using Recursion:--> Insertion in same stack, no use of another stack as buffer.
#include <iostream>
#include <stack>
using namespace std;
void createStack(stack<int>&st, int n) {
    int val;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        cin >> val;
        st.push(val);
    }
}
void insertAtEnd(stack<int>&st, int ele) {
    if(st.empty()) st.push(ele);
    else {
        int x = st.top();
        st.pop();
        insertAtEnd(st, ele);
        st.push(x);
    }
}
void printStack(stack<int>st) {
    int size =st.size();
    for(int i=0; i<size; i++) {
        cout << st.top() << " ";
        st.pop();
    }
}
int main() {
    int n, ele;
    cout << "Enter number of elements: ";
    cin >> n;
    stack <int> st;
    createStack(st, n);
    cout << "Before Insertion: " << endl;
    printStack(st);
    cout << endl << "Enter element to insert at end of stack: ";
    cin >> ele;
    insertAtEnd(st, ele);
    cout << "After Insertion: " << endl;
    printStack(st);
}