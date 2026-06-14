// Q1 Reverse a Linked List
// Q2 Middle of Linked List

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            this->data = d;
        }
        ~Node(){
            cout<<"I am in destructor";
        }
};

class Node1{
    public:
        int data;
        Node1* prev;
        Node1* next;
        Node1(int d){
            this->data = d;
        }
        ~Node1(){
            cout<<"I am in destructor";
        }
};

void reverse(Node* &head){
    /* if(head == NULL) return;
    Node* prev = NULL;
    Node* next = head->next;
    while(head != NULL){
        head->next = prev;
        prev = head;
        head = next;
        if(next != NULL) next = next->next;
    }
    head = prev; */
    // Simplified 
    Node* prev = NULL;
    Node* next = NULL;
    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head = prev;
}

void reverse_recurse(Node* &head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }
    Node* next = curr->next;
    reverse_recurse(head, next, curr);
    curr->next = prev;
}

Node* reverse1(Node* &head){
    if(head == NULL || head -> next == NULL) return head;
    Node* recHead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;
    return recHead;
}

void middleNode(Node* &head){
    // Brute Force
    /* Node* curr = head;
    int length = 0;
    while(curr != NULL){
        length++;
        curr = curr->next;
    }
    int mid = (length/2)+1;
    for(int i = 1; i < mid; ++i) head = head->next; */
    // optimised
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL ){
        slow = slow->next;
        fast = fast->next->next;
    }
    head = slow;
    // return slow;
}

void reverseDoubly(Node1* &head){
    Node1* temp = nullptr;
    Node1* curr = head;
    while(curr != nullptr){
        head = curr;
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = temp;
    }
}

int main(){
    Node* head = new Node(10);
    Node* curr = head;
    Node* prev = NULL;
    reverse_recurse(head, curr, prev);
    return 0;
}