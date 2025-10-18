#include <iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

template<class T>
class Stack
{
    vector<T>vec;

    public:

    void push(T value)
    {
        vec.push_back(value);
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty";
            return;
        }
        vec.pop_back();
    }

    T top()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty";
        }
        return vec[vec.size()-1];
    }

    bool isEmpty()
    {
        return vec.empty();
    }
};

void pushBottom(stack<string>&s, string value)
{
    if(s.empty())
    {
        s.push(value);
        return;
    }
    string temp=s.top();
    s.pop();
    pushBottom(s,value);
    s.push(temp);
}

int main()
{
    stack<string> s;

    for(int i=0;i<3;i++)
    {
        string name;
        cin>>name;
        s.push(name);
    }

    pushBottom(s,"KASHU");

    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}