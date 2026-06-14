#include<iostream>
using namespace std;

//Creating a node
class Node{
    public:
    // Data member
        int data;
        Node* next;
    // Constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }   
    // Destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "memory is free with data" << value <<endl;
    }
};

// Insertion
void InsertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp; // or tail = tail->next
}

void InsertATMiddle(Node* &head, int d, int pos){
    Node* temp = new Node(d);
    Node* curr = head;
    for(int i = 1; i < pos-1; ++i) curr = curr->next;
    temp->next = curr->next;
    curr->next = temp;
    // Node* prev;
    // for(int i = 1; i < pos; ++i){
    //     prev = curr;
    //     curr = curr->next;
    // }
    // prev->next = temp;
    // temp->next = curr;
}

void insert(Node* &head, Node* &tail, int d, int pos){
    Node* temp = new Node(d);
    Node* curr = head;
    for(int i = 1; i < pos-1; ++i) curr = curr->next;
    temp->next = curr->next;
    curr->next = temp;
    if(pos == 1) head = temp;
    if(temp->next == NULL) tail = temp;
}

// Output
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

// Deletion
void deleteNode(Node* &head, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp->next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;
        for(int i = 1; i < pos; ++i){
            prev = curr;
            curr = curr->next;
        } 
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    
}

int main(){
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    Node* head = node1;
    Node* tail = node1;
    // print(head);

    // InsertAtHead(head, 12);
    // print(head);

    // InsertAtHead(head, 15);
    // print(head);

    print(head);

    InsertAtTail(tail, 12);
    print(head);

    InsertAtTail(tail, 15);
    print(head);

    InsertATMiddle(head, 20, 3);
    print(head);

    insert(head, tail, 22, 1);
    insert(head, tail, 100, 4);
    insert(head, tail, 0, 6);
    print(head);

    deleteNode(head, 1);

    print(head);
    return 0;
}