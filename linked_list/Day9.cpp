#include<iostream>
#include<unordered_map>
using namespace std;

// Question : Clone a Linked List with random pointer
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Method 1 : Create a clone list withoout setting random pointer
/* Then iterate again to find the exact random pointer node address distance and point that to the node
TC : O(n^2) SC : O(1) except list*/

// Method 2 : Use map to mark each old node with its new clone node
/* Now create clone list without setting random pointer and
set it through map later. TO find exact node, use map to get old node of curr node
and find random node pointed. Use map again to find which node is pointed by that in clone list
Marks the address.
TC : O(n), SC : O(N)
*/

class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        // Create a clone list
        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;
        Node* temp = head;
        while(temp != nullptr){
            Node* newNode = new Node(temp->val);
            if(cloneHead == nullptr){
                cloneHead = newNode;
                cloneTail = newNode;
            }else{
                cloneTail->next = newNode;
                cloneTail = cloneTail->next;
            } 
            temp = temp->next;
        }

        // Created A map
        unordered_map<Node* , Node*> oldToClone;
        Node* orgNode = head;
        Node* cloneNode = cloneHead;
        while(orgNode && cloneNode){
            oldToClone[orgNode] = cloneNode;
            orgNode = orgNode->next;
            cloneNode = cloneNode->next;
        }

        // Set Random Pointer
        orgNode = head;
        cloneNode = cloneHead;
        while(orgNode){
            cloneNode->random = oldToClone[orgNode->random];
            orgNode = orgNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};

class Solution1_upgrade {
private:
    void insertAtTail(Node* &cloneHead, Node* &cloneTail, int val) {
        Node* newNode = new Node(val);
        if(cloneHead == nullptr){
            cloneHead = newNode;
            cloneTail = newNode;
            return;
        }
        cloneTail->next = newNode;
        cloneTail = newNode;
    }

public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;

        unordered_map<Node*, Node*> oldToClone;
        Node* temp = head;

        // Create clone list + build mapping in one traversal
        while(temp != nullptr){
            insertAtTail(cloneHead, cloneTail, temp->val);
            oldToClone[temp] = cloneTail;
            temp = temp->next;
        }

        // Set random pointers
        Node* orgNode = head;
        Node* cloneNode = cloneHead;
        while(orgNode != nullptr){
            cloneNode->random = oldToClone[orgNode->random];
            orgNode = orgNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};

// Method 3 : TC : O(n), SC : O(1)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAtTail(Node* &cloneHead, Node* &cloneTail, int val) {
        Node* newNode = new Node(val);
        if(cloneHead == nullptr){
            cloneHead = newNode;
            cloneTail = newNode;
            return;
        }
        cloneTail->next = newNode;
        cloneTail = newNode;
    }

public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = nullptr;
        Node* cloneTail = nullptr;

        Node* temp = head;
        // Create clone list
        while(temp != nullptr){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // map old node to new node to next old node
        temp = head;
        Node* currClone = cloneHead;
        while(temp){
            Node* next = temp->next;
            temp->next = currClone;
            Node* next2 = currClone->next;
            currClone->next = next;
            temp = next;
            currClone = next2;
        }
        // Set random pointers
        Node* orgNode = head;
        Node* cloneNode = cloneHead;
        while(orgNode != nullptr){
            cloneNode->random = (orgNode->random) ? orgNode->random->next : nullptr;
            orgNode = orgNode->next->next;
            if(cloneNode->next) cloneNode = cloneNode->next->next;
        }
        // Detach org nodes
        orgNode = head;
        cloneNode = cloneHead;
        while(orgNode && cloneNode){
            orgNode->next = orgNode->next->next;
            if(cloneNode->next) cloneNode->next = cloneNode->next->next;
            orgNode = orgNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};
/* We removed map by changing our clone list and orginal list
We changed next pointer such that each org node next shows its clone node and clone node shows its org node next node
This way to get clone node of the random node, we use next of that
We rearrange it back into orginal structure;
*/

int main(){

    return 0;
}