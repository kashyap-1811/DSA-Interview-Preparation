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

    void print()
    {
        Node* temp=head;

        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp= temp->next;
        }
        cout<<"NULL\n";
    }
};

Node* reverseList(Node* head)
    {
        Node *prev=nullptr;
        Node *curr=head;
        Node *after;

        while(curr!=nullptr)
        {
            after=curr->next;
            curr->next=prev;

            prev=curr;
            curr=after;
        }
          return prev;
    }   

Node* splitAtMiddle(Node* head) 
{
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != nullptr) {
        prev->next = nullptr;
    }

    return slow;
}

void reverse(Node *head)
{
    Node *righthead=splitAtMiddle(head);

    Node *reversedRight = reverseList(righthead);

    //alernate Merging

    Node *left=head;
    Node *right=reversedRight;
    Node *tail=NULL;

    while(left!=NULL && right!=NULL)
    {
        Node *leftnext=left->next;
        Node *rightnext= right->next;

        left->next=right; //2nd element will be right first
        right->next=leftnext;  //3rd will be left 2nd
        tail=right;

        left=leftnext;
        right=rightnext;
    }

    if(right!=NULL)
    {
        tail->next=right;
    }

}

int main()
{
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    //ll.push_back(6);

    ll.print();

    reverse(ll.head);

    ll.print();
    return 0;
}