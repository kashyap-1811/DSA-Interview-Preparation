// #include <bits/stdc++.h>

// using namespace std;

// template<class T>
// class Stack
// {
//     list<T>ll;
//     public:

//     void push(T val)
//     {
//         ll.push_front(val);
//     }
//     void pop()
//     {
//         ll.pop_front();
//     }
//     T top()
//     {
//         return ll.front();
//     }
//     bool isEmpty()
//     {
//         return ll.size()==0;
//     }
// };

// int main()
// {
//     Stack<int>s;

//     s.push(8);
//     s.push(10);
//     s.push(11);

//     while(!s.isEmpty())
//     {
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

template<class T>
class Node
{
    public:
    T data;
    Node *next;

    Node(T val)
    {
        data=val;
        next=nullptr;
    }
};

template<class T>
class Stack
{
    public:
    Node<T> *head;

    Stack()
    {
        head=nullptr;
    }

    void push(T val)
    {
        Node<T> *new_node = new Node<T>(val);
        new_node->next = head;
        head = new_node;
    }

    void pop()
    {
        if(head == nullptr)
        {
            cout<<"Stack is Empty"<<endl;
            return;
        }

        Node<T> *temp=head->next;
        head->next=nullptr;
        delete head;
        head=temp;
    }

    T top()
    {
        return head->data;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
};

int main()
{
        Stack<string>s;

    s.push("Rupareliya");
    s.push("Bharatbhai");
    s.push("Kashyap");

    while(!s.isEmpty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}