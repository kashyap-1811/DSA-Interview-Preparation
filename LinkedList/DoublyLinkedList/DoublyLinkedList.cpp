#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int val=0)
    {
        data=val;
        prev=next=0;
    }
};

class DoubleList
{
    public:
    Node *head;
    Node *tail;

    DoubleList()
    {
        head=tail=nullptr;
    }

    void push_front(int val)
    {
        Node *temp = new Node(val);

        if(head==NULL)
        {
            head=tail=temp;
        }
        else{
           temp->next=head;
           head->prev=temp;
           head=temp;
        }
    }

    void pop_front()
    {
        Node *temp=head;
        head=head->next;

        head->prev=NULL;

        temp->next=NULL;
        delete temp;
    }

    void  push_back(int val)
    {
        Node *temp= new Node(val);
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }

    void pop_back()
    {
        Node *temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        delete temp;
    }

    void print()
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

    void backwardPrint()
    {
        Node *temp=tail;

        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->prev;
        }
        cout<<"NULL\n";
    }
};

int main()
{
    DoubleList ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    ll.push_front(6);
    ll.push_front(7);
    ll.push_front(8);

    cout<<"Forward Print: ";
    ll.print();
    cout<<"Backward Print ";
    ll.backwardPrint();

    ll.pop_front();
    ll.pop_front();
    ll.pop_front();

    ll.push_back(9);
    ll.push_back(10);

    ll.pop_back();

    cout<<"Forward Print: ";
    ll.print();
    return 0;
}