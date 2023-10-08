// STL class Stack (Stack container Adapter)
/*
    --> As stack is an important data structure, Standard Template Library [STL] in C++ provids a class to implement a stack in a program.
    --> In-built class name is stack;
    --> Header file name is stack;
    --> Some in-built operations include:-
        -> size = Returns the actual number of elements in the stack;
        -> empty = Returns true if stack is empty, otherwise false.
        -> push(item) = Insert an item into the stack.
        -> top = Returns the top element from stack.
        -> pop = Removes the top element from the stack.
*/

#include <iostream>
#include <stack>
using namespace std;
void display(stack<int> st);
int main()
{
    stack<int> mystack;
    int val, ch, flag = 1;
    cout << "1. Push element \n2. Pop element \n3. Top element \n4. isempty \n5. Size\n6. Display elements \n7. Exit" <<endl;
    while (flag)
    {
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cin >> val;
            mystack.push(val);                  // Push element into the stack
            break;

        case 2:
            if (mystack.empty())
                cout << "Stack Underflow" << endl;      // To check whether stack is empty or not
            else
                mystack.pop();                  // Pop element from stack
            break;

        case 3:
            if (mystack.empty())
                cout << "No element" << endl;
            else
                cout << mystack.top() << endl;          // Displaying top element
            break;

        case 4:
            if (mystack.empty())
                cout << "Stack is empty." << endl;      // Checking whether stack is empty or not.
            else cout << "Not empty" << endl;
            break;

        case 5:
            cout << "Size: " << mystack.size() << endl;         // Displaying size of stack
            break;

        case 6:
            cout << "Elements: ";                       // Displaying all stack elements
            display(mystack);
            cout << endl;
            break;

        case 7:
            flag = 0;                       // To exit
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}

void display(stack <int> st)                // Copy of original stack is passed.
{
    while(!st.empty())
    {
        cout <<st.top() << " ";
        st.pop();
    }
}