#include<iostream>
using namespace std;

// Q1 sort 0s, 1s, 2s in LinkedList
// Method 1 : Frequency count and replace values accordingly in order
struct Node{
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {};
    Node(int x) : val(x), next(nullptr) {};
    Node(int x, Node* next) : val(x), next(next) {};
};

// Self Help function to create an array to LL
Node* createArrToLinkList(int arr[], int n){
    if(n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1; i < n; ++i){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Function to print
void printList(Node* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << '\n';
}

// Sort Function 
void sort012(Node* head){
    int zero = 0, one = 0, two = 0;
    Node* temp = head;
    while(temp != nullptr){
        if(temp->val == 0) zero++;
        else if(temp->val == 1) one++;
        else two++;
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        if(zero > 0){
            temp->val = 0;
            zero--;
        }else if(one > 0){
            temp->val = 1;
            one--;
        }else{
            temp->val = 2;
            two--;
        }
        temp = temp->next;
    }
}

Node* sort012inPlace(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    
    Node* ZeroHead = new Node(-1);
    Node* ZeroTail = ZeroHead;
    Node* OneHead = new Node(-1);
    Node* OneTail = OneHead;
    Node* TwoHead = new Node(-1);
    Node* TwoTail = TwoHead;
    while(head != nullptr){
        if(head->val == 0){
            ZeroTail->next = head;
            ZeroTail = head;
        }else if(head->val == 1){
            OneTail->next = head;
            OneTail = head;
        }else{
            TwoTail->next = head;
            TwoTail = head;
        }
        head = head->next;
    }
    // Merge
    ZeroTail->next = (OneHead->next ? OneHead->next : TwoHead->next);
    OneTail->next = TwoHead->next;
    TwoTail->next = nullptr;
    
    if(ZeroHead->next) head = ZeroHead->next;
    else if(OneHead->next) head = OneHead->next;
    else head = TwoHead->next;
    delete ZeroHead;
    delete OneHead;
    delete TwoHead;
    return head;

}

// Q2 Merge Two Sorted List
// leetcode 21 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                curr->next = list1;
                curr = list1;
                list1 = list1->next;
            }else{
                curr->next = list2;
                curr = list2;
                list2 = list2->next;
            }
        }
        while(list1 != nullptr){
            curr->next = list1;
            curr = list1;
            list1 = list1->next;
        }
        while(list2 != nullptr){
            curr->next = list2;
            curr = list2;
            list2 = list2->next;
        }
        return dummy->next;
    }
};

template <typename T>
class NodeT{
    public:
        T data;
        NodeT* next;
        NodeT(T data){
            next = nullptr;
            this->data = data;
        }
        ~NodeT(){
            if(next != NULL){
                delete next;
            }
        }
};

NodeT<int>* solve(NodeT<int>* first, NodeT<int>* second){
    
    if(first->next == nullptr){
        first->next = second;
        return first;
    }
    
    NodeT<int>* curr1 = first;
    NodeT<int>* next1 = curr1->next;
    NodeT<int>* curr2 = second;
    NodeT<int>* next2 = curr2->next;
    while(next1 != nullptr && curr2 != nullptr){
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }else{
            curr1 = next1;
            next1 = next1->next;
            if(next1 == nullptr){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

NodeT<int>* sortTwoLists(NodeT<int>* first, NodeT<int>* second){
    if(first == nullptr) return second;
    if(second == nullptr) return first;
    if(first->data <= second->data) return solve(first,second);
    else return solve(second,first);
}

int main(){
    int arr[] = {1, 2, 0, 1, 2, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createArrToLinkList(arr, n);

    cout << "Before: ";
    printList(head);

    head = sort012inPlace(head);

    cout << "After: ";
    printList(head);

    return 0;
}