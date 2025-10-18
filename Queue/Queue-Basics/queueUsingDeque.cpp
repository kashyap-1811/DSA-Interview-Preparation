#include <bits/stdc++.h>

using namespace std;

class Queue
{
    deque<int>dq;

    public:

    void push(int data)
    {
        dq.push_back(data);
    }

    int front()
    {
        if(dq.empty())
        {
            return -1;
        }

        return dq.front();
    }

    void pop()
    {
        if(dq.empty())
        {
            cout<<"Queue is Empty\n";
            return;
        }
        dq.pop_front();
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    return 0;
}