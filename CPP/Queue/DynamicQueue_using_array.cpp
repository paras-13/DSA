// Dynamic Queue using array;
// Their is no Overflow Condition

#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    T *arr;
    int front;
    int rear;
    int capacity;
    int size;
    public:
    Queue()
    {
        capacity = 10;
        arr = new T[capacity];
        front = -1;
        rear = 0;
        size = 0;
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    int getSize()
    {
        return size;
    }

    void push(T element)   //Function for Dynamic Queue
    {
        if (size == capacity)
        {
            T* newArr = new T[capacity * 2];
            int temp = front;
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[temp];
                temp = (temp + 1) % capacity;
            }
            capacity = capacity * 2;
            delete[] arr;
            arr = newArr;
            front = 0;
            rear = size;
        }
        arr[rear] = element;
        rear = (rear + 1) % capacity;
        if (front == -1)
            front = 0;
        size++;
    }

    T getFront()
    {
        if (!isEmpty())
            return arr[front];
        else
        {
            cout << "Empty Queue" << endl;
            return 0;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            front = (front + 1) % capacity;
            size--;
            cout << "Element Popped" << endl;
            if (size == 0)
            {
                rear = 0;
                front = -1;
            }
        }
        else
        {
            cout << "Empty Queue" << endl;
            return;
        }
    }

    void Display()
    {
        if (!isEmpty())
        {
            cout << "Displaying Elements: ";
            int i = front;
            for (int t = 0; t < size; t++)
            {
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << endl;
        }
        else
            cout << "Empty Stack";
    }
};
int main()
{
    class Queue<int> q;
    class Queue<char> q2;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(90);
    q.push(100);
    q.push(110);
    q.push(120);

    cout << "Front:" << q.getFront() << endl;
    q.pop();

    cout << "Front:" << q.getFront() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
    q.push(60);
    q.push(70);
    cout << "Front:" << q.getFront() << endl;

    q2.push('A');
    q2.push('B');
    q2.push('C');
    q2.push('D');
    q2.push('E');
    q2.push('F');
    q2.push('H');
    q2.push('I');
    q2.push('J');
    q2.push('K');
    q2.push('L');

    q2.pop();

    cout << "Front:" << q2.getFront() << endl;
    cout << q2.getSize() << endl;

    q.Display();
    q2.Display();
    return 0;
}
