// Implement Stack using Single Queue
// Time Complexity: Push: O(n), Pop: O(1), Top: O(1), Empty: O(1)
// Space Complexity: O(n)

#include <iostream>
#include <queue>
using namespace std;
class Stack {
    private:
    queue<int>q;
    public:
    void push(int val) {
        int s = q.size();
        q.push(val);
        for(int i=0; i<s; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << val << " pushed onto the stack\n";
    }
    int pop() {
        if(q.size() == 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        int val = q.front();
        q.pop();
        return val;
    }
    int top() {
        if(q.size() == 0) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }
    bool empty() {
        return q.size() == 0;
    }
    void display() {
        queue<int> tq = q;
        while(!tq.empty()) {
            cout << tq.front() << " ";
            tq.pop();
        }
        cout << endl;
    }
};
int main() {
    Stack st;
    st.push(0);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << "Elements in the stack: ";
    st.display();
    cout << st.pop() << " popped from the stack\n";
    cout << st.pop() << " popped from the stack\n";
    cout << st.pop() << " popped from the stack\n";
    cout << st.top() << " is at the top of the stack\n";
    cout << "Elements in the stack: ";
    st.display();
    return 0;
}