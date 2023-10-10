// Queue Implementation Using Linked List with templates.

#include <iostream>
using namespace std;
template <typename T>
class Node
{
    public:
    T data;
    Node<T>* next;
    Node(T x)
    {
        data = x;
        next = NULL;
    }
};

template <typename T>
class Queue
{
    private:
    Node<T>* front;
    Node<T>* rear;
    int size;

    public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return (size == 0);
    }

    void push(T ele)
    {
        Node<T>* newnode = new Node(ele);
        newnode->next = NULL;
        if(front == NULL){front = newnode; rear = newnode;}
        else {rear->next = newnode; rear = newnode;}
        size++;
    }

    T getFront()
    {
        if(!isEmpty())
        {
            return front->data;
        }
        else {"Empty queue\n"; return 0;}
    }

    void pop()
    {
        if(!isEmpty())
        {
            Node<T>* temp = front;
            front = front->next;
            temp->next = NULL;
            delete temp;
            size--;
        }
        else {cout << "Empty queue\n";}
    }

    void Display()
    {
        if(!isEmpty())
        {
            cout << "Displaying Elements: ";
            Node<T>* temp = front;
            while(temp!=NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
            delete temp;
        }
        else cout << "Empty Queue\n";
    }

};

int main()
{
    class Queue<int> q1;
    class Queue<char> q2;

    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    q1.push(60);
    q1.push(70);
    q1.push(80);
    q1.push(90);

    q1.pop();
    q1.pop();
    q1.pop();

    cout << "Front: " << q1.getFront() << endl;
    cout << "Size: " << q1.getSize() << endl;
    cout << q1.isEmpty() << endl;

    q2.push('U');
    q2.push('K');
    q2.push('U');
    q2.push('P');
    q2.push('A');
    q2.push('D');
    q2.push('H');
    q2.push('Y');
    q2.push('A');
    q2.push('Y');

    q2.pop();
    q2.pop();

    cout << "Front: " << q2.getFront() << endl;
    cout << "Size: " << q2.getSize() << endl;
    cout << q2.isEmpty() << endl;

    q1.Display();
    q2.Display();

    return 0;
}