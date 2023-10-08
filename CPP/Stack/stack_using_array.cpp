/*
 As all the elements in a stack are of same type and arranged in a linear data structure
 and operates on LIFO order. It can be implemented using an array.
 Operations:-
 -> Push
 -> Pop
 -> Top
 -> isFullStack
 -> isEmptyStack
 -> size

*/

#include <iostream>
using namespace std;

const int MAX = 100;
class Stack
{
private:
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }
    bool isEmptyStack();
    bool isFullStack();
    void Push(int element);
    void Pop();
    int Top();
    int Size();
    void Display();
};

bool Stack ::isEmptyStack() { return (top == -1); }
bool Stack ::isFullStack() { return (top == MAX - 1); }

void Stack ::Push(int element)
{
    if (!isFullStack())
    {
        top++;
        arr[top] = element;
        cout << "Element " << element << " pushed onto the stack\n";
    }
    else
        cout << "Stack Overflow(Full). Cannot push element.\n";
}

void Stack ::Pop()
{
    if (!isEmptyStack())
    {
        top--;
        cout << "Element popped\n";
    }
    else
        cout << "Stack Underflow. No element to pop\n";
}

int Stack ::Top()
{
    if (!isEmptyStack())
        return arr[top];
    else
    {
        cout << "Stack is empty\n";
        return -1;
    }
}

int Stack ::Size()
{
    if (!isEmptyStack()) {return top + 1;}
    else return 0;
}

void Stack ::Display()
{
    if (!isEmptyStack())
    {
        cout << "Displaying Stack elements: ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    else
        cout << "Stack is Empty\n";
}

int main()
{
    class Stack mystack;
    int ch, val, flag=1;
    cout << "1. Push\n2. Pop\n3. Top\n4. isEmpty\n5. isFull\n6. Size\n7. Display\n8. Exit\n";
    cout << "Enter you choice: ";
    while(flag)
    {
        cin >> ch;
        switch(ch)
        {
            case 1:
                cin >> val;
                mystack.Push(val);
                break;
            
            case 2:
                mystack.Pop();
                break;

            case 3:
                cout << "Top Element: " << mystack.Top();
                break;

            case 4:
                if(mystack.isEmptyStack()) cout << "Stack is Empty\n";
                else cout << "Stack is not empty\n";
                break;
            
            case 5:
                if(mystack.isFullStack()) cout << "Stack is Full\n";
                else cout << "Not Full\n";
                break;

            case 6:
                cout << "Stack size: " << mystack.Size() << endl;
                break;

            case 7:
                mystack.Display();
                break;

            case 8:
                flag = 0;
                break;

            default:
                cout << "Invalid Choice\n";
                break;
        }
    }    
}