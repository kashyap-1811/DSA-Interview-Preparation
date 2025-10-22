// leet - 432
// https://leetcode.com/problems/all-oone-data-structure/
 
#include <bits/stdc++.h>
using namespace std;
 
#include <bits/stdc++.h>
using namespace std;

class AllOne {
private:
    struct Node {
        int freq;
        unordered_set<string> keys;
        Node *prev, *next;
        Node(int f) : freq(f), prev(nullptr), next(nullptr) {}
    };

    Node *head, *tail;
    unordered_map<string, Node*> keyNode;
    unordered_map<int, Node*> freqNode;

    void insertAfter(Node* node, Node* newNode) {
        newNode->next = node->next;
        newNode->prev = node;
        node->next->prev = newNode;
        node->next = newNode;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        freqNode.erase(node->freq);
        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (keyNode.find(key) == keyNode.end()) {
            // New key with frequency 1
            if (freqNode.find(1) == freqNode.end()) {
                Node* newNode = new Node(1);
                insertAfter(head, newNode);
                freqNode[1] = newNode;
            }
            freqNode[1]->keys.insert(key);
            keyNode[key] = freqNode[1];
        } else {
            Node* curr = keyNode[key];
            int newFreq = curr->freq + 1;
            // Ensure next frequency node exists
            if (freqNode.find(newFreq) == freqNode.end()) {
                Node* newNode = new Node(newFreq);
                insertAfter(curr, newNode);
                freqNode[newFreq] = newNode;
            }
            freqNode[newFreq]->keys.insert(key);
            keyNode[key] = freqNode[newFreq];

            // Remove key from old node
            curr->keys.erase(key);
            if (curr->keys.empty()) remove(curr);
        }
    }

    void dec(string key) {
        if (keyNode.find(key) == keyNode.end()) return;

        Node* curr = keyNode[key];
        int newFreq = curr->freq - 1;

        // Remove key from current node
        curr->keys.erase(key);

        if (newFreq > 0) {
            // Ensure previous frequency node exists
            if (freqNode.find(newFreq) == freqNode.end()) {
                Node* newNode = new Node(newFreq);
                insertAfter(curr->prev, newNode);
                freqNode[newFreq] = newNode;
            }
            freqNode[newFreq]->keys.insert(key);
            keyNode[key] = freqNode[newFreq];
        } else {
            // Frequency is 0 → remove key completely
            keyNode.erase(key);
        }

        // Remove old node if empty
        if (curr->keys.empty()) remove(curr);
    }

    string getMaxKey() {
        if (tail->prev == head) return "";
        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if (head->next == tail) return "";
        return *(head->next->keys.begin());
    }
};
