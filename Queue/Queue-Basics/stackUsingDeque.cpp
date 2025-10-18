#include <bits/stdc++.h>

using namespace std;

class Stack
{   
    deque<int>dq;

    public:

    void push(int data)
    {
        dq.push_back(data);
    }  

    void pop()
    {
        if(dq.empty())
        {
            cout<<"Stack is Empty\n";
            return;
        }
        dq.pop_back();
    }

    int top()
    {
        if(dq.empty())
        {
            return -1;
        }
        return dq.back();
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