// Circular Queue through array implementation using templates.

#include <iostream>
using namespace std;
template <typename T>
class Queue
{
    T* arr;
    int front;
    int rear;
    int capacity;
    int size;
    public:
        Queue()
        {
            capacity = 5;
            arr = new T[capacity];
            rear = 0;
            front = -1;
            size = 0;
        }
        Queue(int cap)
        {
            capacity = cap;
            arr = new T[capacity];
            rear = 0;
            front = -1;
            size = 0;
        }

        int getSize(){
            return size;
        }
        bool isEmpty(){
            return (size == 0);
        }
        void push(T ele){
            if(size == capacity){
                cout << "Queue Full" << endl;
                return;
            }
            arr[rear] = ele;
            rear = (rear+1)%capacity;     // Moving circularly in queue
            if(front == -1) front=0;
            size++; 
        }
        T getFront()
        {
            if(!isEmpty())
            return arr[front];
            else {cout << "Empty Queue" << endl; return 0;}
        }

        void pop()
        {
            if(!isEmpty()){
                front = (front+1)%capacity;
                size--;
                cout << "Element Popped" << endl;
                if(size == 0) {rear = 0; front = -1;}
            }
            else {cout << "Empty Queue"<< endl; return;}

        }

        void Display()
        {
            if(!isEmpty()) 
            {
                cout << "Displaying Elements: ";
                int i=front;
                for(int t = 0; t<size; t++)
                {
                    cout << arr[i] << " ";
                    i = (i+1)%capacity;
                }
                cout << endl;
            }
            else cout << "Empty Stack";
        }
};
int main()
{
    class Queue<int> q(5);
    class Queue<char> q2(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    cout << "Front:" << q.getFront() << endl;
    q.pop();
    q.pop();
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
    q2.push('G');

    q2.pop();
    q2.pop();
    cout << "Front:" << q2.getFront() << endl;
    cout << q2.getSize() << endl;

    q.Display();
    q2.Display();
    return 0;
}
