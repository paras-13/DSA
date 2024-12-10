// Implementing Queue using Stack
// Using Two stacks
// Time Complexity: Push: O(n), Pop: O(1), Front: O(1), Empty: O(1)
// Space Complexity: O(n)

#include <iostream>
#include <stack>
using namespace std;
class Queue {
    private:
    stack<int>input, output;
    public:
    void push(int n) {
        while(!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        input.push(n);
        while(!output.empty()) {
            input.push(output.top());
            output.pop();
        }
        cout << n << " pushed onto the queue\n";
    }
    int pop() {
        if(input.size() == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = input.top();
        input.pop();
        return val;
    }
    int front() {
        if(input.size() == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return input.top();
    }
    bool empty() {
        return input.size() == 0;
    }
    void display() {
        stack<int> temp = input;
        while(!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.display();
    cout << q.pop() << " popped from the queue\n";
    cout << q.pop() << " popped from the queue\n";
    cout << q.pop() << " popped from the queue\n";
    cout << q.front() << " is at the front of the queue\n";
    q.display();
    return 0;
}