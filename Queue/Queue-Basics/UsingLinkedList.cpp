#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:

    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }

    ~Node()
    {
        if(next!=nullptr)
        {
            delete next;
            next=nullptr;
        }
    }
};

class Queue
{
    public:
    Node *head;
    Node *tail;

    Queue()
    {
        head=tail=nullptr;
    }

    void push(int data)
    {
        Node *new_node = new Node(data);
        if(head == nullptr)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail=new_node;
        }
    }

    bool isEmpty()
    {
        if(head == nullptr)
            return true;

        return false;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty\n";
            return;
        }
        Node *temp = head->next;
        head->next = nullptr;
        delete head;
        head = temp;
    }

    int front()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty\n";
            return -1;
        }
        return head->data;
    }
};

int main()
{
    Queue q;
    q.push(0);
    q.push(1);
    q.push(2);

    for(int i=0;i<4;i++)
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}