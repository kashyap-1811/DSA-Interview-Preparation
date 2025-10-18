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

Node* merge(Node *lh, Node *rh)
{
    // List ans;

    // Node *i=lh;
    // Node *j=rh;

    // while(i!=NULL && j!=NULL)
    // {
    //     if(j->data <= i->data)
    //     {
    //         ans.push_back(j->data);
    //         j=j->next;
    //     }
    //     else
    //     {
    //         ans.push_back(i->data);
    //         i=i->next;
    //     }
    // }

    // while(i!=NULL)
    // {
    //     ans.push_back(i->data);
    //     i=i->next;
    // }

    // while(j!=NULL)
    // {
    //     ans.push_back(j->data);
    //     j=j->next;
    // }

    // return ans.head;

/*---------------------optimal Solution------------------------------------*/
    if (lh == nullptr) return rh;
    if (rh == nullptr) return lh;

    Node* mergedHead = nullptr;

    if (lh->data < rh->data) {
        mergedHead = lh;
        lh = lh->next;
    } else {
        mergedHead = rh;
        rh = rh->next;
    }

    Node* mergedTail = mergedHead;

    while (lh != nullptr && rh != nullptr) {
        if (lh->data < rh->data) {
            mergedTail->next = lh;
            lh = lh->next;
        } else {
            mergedTail->next = rh;
            rh = rh->next;
        }
        mergedTail = mergedTail->next;
    }

    if (lh != nullptr) {
        mergedTail->next = lh;
    } else {
        mergedTail->next = rh;
    }

    return mergedHead;
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

Node* mergeSort(Node *head)
{
    if(head==NULL || head->next==NULL)
        return head;

    Node *rightHead = splitAtMiddle(head);

    Node* left = mergeSort(head);  //left half
    Node* right = mergeSort(rightHead);  //right Half

    return  merge(left, right);
}

int main()
{
    List ll;
    ll.push_back(9);
    ll.push_back(8);
    ll.push_back(7);
    ll.push_back(9);
    ll.push_back(8);
    ll.push_back(7);

    ll.print();

    ll.head= mergeSort(ll.head);

    ll.print();
    return 0;
}