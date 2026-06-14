#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int d){
            this->data = d;
            this->prev = NULL;
            this->next = NULL;
        }
};

void print(Node* head){
    while(head != NULL){
        cout<< head -> data << " ";
        head = head -> next;
    }
    cout<<endl;
}

int getLength(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head -> next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, Node* &tail, int d){
    Node* temp = new Node(d);
    if(tail == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insert(Node* &head, Node* &tail, int pos, int d){
    if(pos == 1){
        insertAtHead(head, tail, d);
        return;
    }
    Node* curr = new Node(d);
    Node* prv = head;
    for(int i = 1; i < pos-1; ++i) prv = prv->next;
    if(prv->next == NULL){
        insertAtTail(head, tail, d);
    }
    Node* nxt = prv->next;
    prv->next = curr;
    curr->prev = prv;
    curr->next = nxt;
    nxt->prev = curr;
}

int main(){
    // Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    // cout<<getLength(head);

    insertAtHead(head, tail, 11);
    insertAtHead(head, tail, 13);
    insertAtHead(head,tail, 0);
    
    insertAtTail(head, tail, 25);
    print(head);

    insert(head, tail, 2, 100);
    print(head);

    return 0;
}