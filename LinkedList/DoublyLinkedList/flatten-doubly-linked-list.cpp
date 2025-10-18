// leet - 430
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
 
#include <bits/stdc++.h>
using namespace std;
 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* recurse(Node *head){
        Node *prev = nullptr;
        Node *curr = head;
        Node *succ = head->next;

        while(curr){
            if(curr->child){
                curr->next = curr->child;
                curr->child->prev = curr;
                Node *last = recurse(curr->child);
                curr->child = nullptr;
                last->next = succ;
                if(succ)
                    succ->prev = last;
            }

            prev = curr;
            curr = succ;
            if(succ)
                succ = succ->next;
        }

        while(prev->next != nullptr)
            prev = prev->next;
        return prev;
    }

    Node* flatten(Node* head) {
        if(head == nullptr) 
            return head;

        recurse(head);

        return head;
    }
};