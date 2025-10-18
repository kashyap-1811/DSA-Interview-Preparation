//Floyd's cycle finding Algorithm 

#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val=0 ,Node *ptr=nullptr)
    {
        data=val;
        next=ptr;
    }
};

class List
{
    public:
    Node *head;
    Node *tail;

    List()
    {
        head=nullptr;
        tail=nullptr;
    }

    void pushfront(int val)
    {
        Node *new_node= new Node(val,head);

        if(head==nullptr)
            head=tail=new_node;
        else
            head=new_node;
    }

    void push_back(int val)
    {
        Node* new_node= new Node(val);
        if(head==nullptr)
        {
            head=tail=new_node;
        }
        else
       {
            tail->next=new_node;
            tail=new_node;
        }
    }

    void pop_front()
    {
        if(head==nullptr)
        {
            cout<<"List is Empty"<<endl;
        }
        Node* temp=head;
        head=head->next;
        temp->next=nullptr;
        delete temp;
    }

    void print()
    {
        Node* temp=head;

        while(temp!=nullptr)
        {
            cout<<temp->data<<"->";
            temp= temp->next;
        }
        cout<<"NULL\n";
    }
};

void removeCycle(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    bool iscycle=false;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)
        {
            iscycle=true;
            break;
        }
    }

    if(!iscycle)  //return if no cycle exists
        return;

    slow=head;

    if(slow==fast)
    {
        while(fast->next!=slow)
            fast=fast->next;

        fast->next=nullptr;
    }
    else
    {
        Node *prev=fast;
        while(slow!=fast)  
        {
            prev=fast;
            slow=slow->next;
            fast=fast->next;
        }

        prev->next=nullptr;
    }
}

int main()
{
    List ll;
    ll.push_back(9);
    ll.push_back(8);
    ll.push_back(7);

    ll.tail->next=ll.head;

    removeCycle(ll.head);

    ll.print();
    return 0;
}