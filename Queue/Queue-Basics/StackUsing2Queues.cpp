#include <bits/stdc++.h>

using namespace std;

class Stack
{
    queue<int>q1;
    queue<int>q2;

    public:

    void push(int data)
    {
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(data);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop()
    {
        if(q1.empty())
        {
            cout<<"Stack is empty\n";
            return;
        }
        q1.pop();
    }

    int top()
    {
        if(q1.empty())
        {
            return -1;
        }
        return q1.front();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    return 0;
}