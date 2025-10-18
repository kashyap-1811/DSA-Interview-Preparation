#include <bits/stdc++.h>

using namespace std;

//             using push->O(n)
// class Queue
// {
//     stack<int>s1;
//     stack<int>s2;

//     public:

//     void pop()
//     {
//         if(s1.empty())
//         {
//             cout<<"Queue is empty\n";
//             return;
//         }
//         s1.pop();
//     }

//     int top()
//     {
//         if(s1.empty())
//         {
//             return -1;
//         }
//         return s1.top();
//     }

//     void push(int data)
//     {
//         while(!s1.empty())
//         {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(data);
//         while(!s2.empty())
//         {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }
// };

//         using pop->O(n)
class Queue
{   
    stack<int>s1;
    stack<int>s2;

    public:

    int top()
    {
        if(s1.empty())
        {
            return -1;
        }
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int temp = s2.top();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }

    void push(int data)
    {
        s1.push(data);
    }

    void pop()
    {
        if(s1.empty())
        {
            cout<<"Queue is Empty\n";
            return;
        }
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
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