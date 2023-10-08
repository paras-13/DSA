// Stack implementation using Linked List....

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

class Stack
{
    private:
    Node* top;

    public:
    Stack(){top = NULL;}
    bool isEmptyStack();
    void Push(int element);
    void Pop();
    int Top();
    int Size();
    void Display();
};

bool Stack :: isEmptyStack() {return (top == NULL);}
void Stack :: Push(int element)
{
    Node* newnode = new Node(element);
    newnode->next = top;
    top = newnode;
    cout << "Element "<<element<<" pushed onto stack\n";
}

void Stack :: Pop()
{
    if(!isEmptyStack()) {top = top->next;cout << "Element Popped\n";}
    else cout << "Underflow, stack empty.\n";
}

int Stack :: Top()
{
    if(!isEmptyStack()) return top->data;
    else {cout << "Stack is Empty!\n"; return -1;}
}

int Stack :: Size()
{
    int ct=0;
    Node* temp = top;
    if(top==NULL) return 0;
    while(temp->next!=NULL)
    {
        ct++;
        temp=temp->next;
    }
    return ct;
    delete temp;
}

void Stack :: Display()
{
    cout << "Displaying Stack Elements: ";
    Node* temp = top;
    while(temp!=NULL)
    {
        cout << temp->data <<" ";
        temp=temp->next;
    }
    cout << endl;
    delete temp;
}

int main()
{
    class Stack mystack;
    int ch, val, flag=1;
    cout << "1. Push\n2. Pop\n3. Top\n4. isEmpty\n5. Size\n6. Display\n7. Exit\n";
    cout << "Enter your choice: ";
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
                cout << "Stack size: " << mystack.Size() << endl;
                break;

            case 6:
                mystack.Display();
                break;

            case 7:
                flag = 0;
                break;

            default:
                cout << "Invalid Choice\n";
                break;
        }
    }    
}