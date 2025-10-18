// leet - 328
// https://leetcode.com/problems/odd-even-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *l1 = head;
        ListNode *l2 = head->next;

        ListNode *temp1 = l1;
        ListNode *temp2 = l2;

        while (temp1->next != nullptr && temp2->next != nullptr)
        {
            temp1->next = temp2->next;
            temp1 = temp1->next;
            temp2->next = temp1->next;
            temp2 = temp2->next;
        }

        if (temp1 != nullptr)
            temp1->next = nullptr;
        if (temp2 != nullptr)
            temp2->next = nullptr;

        temp1 = l1;
        while (temp1->next != nullptr)
            temp1 = temp1->next;

        temp1->next = l2;

        return l1;
    }
};