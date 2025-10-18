#include <bits/stdc++.h>

using namespace std;

class Queue
{
    int *arr;
    int capacity;
    int size;
    int front, rear;

    public:
    Queue(int capacity)
    {
        this->capacity=capacity;
        size=0;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }

    void push(int data)
    {
        if(size == capacity)
        {
            cout<<"Queue is Full\n";
            return;
        }
        rear = (rear +1)%capacity;
        arr[rear] = data;
        size++;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty\n";
            return;
        }
        front = (front+1)%capacity;
        size--; 
    }

    int top()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
        if(size == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q(4);
    q.push(9);
    q.push(8);
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();

    return 0;
}