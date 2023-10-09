// Stack using Template;
// Using templates stacks with multiple data types can be formed

#include <iostream>
using namespace std;
template <typename T>

class Stack
{
    private:
    int top;
    int MAX_SIZE;
    T* arr;

    public:
    Stack()
    {
        top = -1;
        MAX_SIZE = 10;
        arr = new T[MAX_SIZE];
    }
    bool isEmpty() {return (top == -1);};
    void Push(T element)
    {
    if(!isEmpty())
    {
        top++;
        arr[top] = element;
        cout << "Element " << element << " pushed onto the stack\n";
    }
    else
    {
        T* newArr = new T[MAX_SIZE*2];
        for(int i=0; i<MAX_SIZE; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
        MAX_SIZE = MAX_SIZE*2;
        top++;
        arr[top] = element;
        cout << "Element " << element << " pushed onto the stack\n";
    }
}
    void Pop()
    {
        if(!isEmpty())
    {
        top--;
        cout << "Element Popped\n";
    }
    else cout << "Stack is empty\n";
    }

    T Top()
    {
        if(!isEmpty()) return arr[top];
        else {cout << "Empty Stack\n"; return 0;}
    }

    int Size()
    {
        if (!isEmpty()) {return Top + 1;}
        else return 0;
    }

    void Display()
    {
        if (!isEmpty())
        {
            cout << "Displaying Stack elements: ";
            for (int i = 0; i <= top; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        else cout << "Stack is Empty\n";
    }
};

int main()
{
    class Stack<int> mystack;
    class Stack<char> mystack2;
    class Stack<double> mystack3;

    mystack.Push(4);
    mystack.Push(5);
    mystack.Push(6);
    mystack.Push(7);
    mystack.Push(8);

    mystack2.Push('A');
    mystack2.Push('B');
    mystack2.Push('C');
    mystack2.Push('D');
    mystack2.Push('E');

    mystack3.Push(1.11);
    mystack3.Push(2.21);
    mystack3.Push(3.31);
    mystack3.Push(4.41);
    mystack3.Push(5.51);

    mystack.Display();
    mystack2.Display();
    mystack3.Display();



    return 0;
}
