/*
    Heap is a CBT(complete Binary Tree)

    CBT means first the current level is filled completely and
    then new children are added to new level

    Nodes are added from left to right

    parent >= children -->MAX HEAP
    parent <= children -->MIN HEAP

    insert --> O(logn)
    pop --> O(logn)
    top --> O(1)


    => for any parent to get child in vector
    left child -> (2 * i) + 1;
    right child = (2 * i) + 2;

    => for any child at x index to get parent index
    par[child] = (x - 1) / 2;
*/

#include <bits/stdc++.h>

using namespace std;

void insert(vector<int> &CBT, int value) // O(logn)
{
    CBT.push_back(value);
    int childIdx = CBT.size()-1;

    while(childIdx > 0)
    {
        int parentIdx = (childIdx-1)/2;

        if(CBT.at(childIdx) > CBT.at(parentIdx))      //vice versa for MIN HEAP
            swap(CBT.at(childIdx) , CBT.at(parentIdx));
        else
            break;
        
        childIdx = parentIdx;
    }
}


/*
    delete
    1) swap(root,last)
    2) delete last idx
    3) fix the heap(Heapify)
*/
void heapify(vector<int>&CBT, int idx) //O(logn)
{
    if(idx >= CBT.size())
        return;
    
    int left = (2 * idx) + 1;
    int right  = (2 * idx) + 2;
    int maxI = idx;

    if(left < CBT.size() && CBT[maxI] < CBT[left])
        maxI = left;
    if(right < CBT.size() && CBT[maxI] < CBT[right])
        maxI = right;

    swap(CBT[idx], CBT[maxI]);

    if(maxI != idx)
        heapify(CBT, maxI); //maxI is the left or right index whichever be the greater

}

void pop(vector<int>&CBT)
{
    //step1
    swap(CBT[0], CBT[CBT.size()-1]);

    //step2
    CBT.pop_back();

    //step3
    heapify(CBT, 0);
}

int top(const vector<int>&CBT)
{
    return CBT[0];
}

void print(const vector<int> &CBT)
{
    for(auto i : CBT)
        cout<<i<<" ";
}

int main()
{
    vector<int> CBT;
    insert(CBT,9);
    insert(CBT,4);
    insert(CBT,8);
    insert(CBT,1);
    insert(CBT,2);
    insert(CBT,5);

    while(CBT.size())
    {
        cout<<top(CBT)<<" ";
        pop(CBT);
    }

    return 0;
}