struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base Case if leftover needed to be updated simultaneously
        // if(head == nullptr) return nullptr;
        // Base Case : If nodes < k, remain same
        ListNode* temp = head;
        for(int i = 0; i < k; ++i){
            if(temp == nullptr) return head;
            temp = temp->next;
        }

        // rev first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int count = 0;
        while(curr != nullptr && count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Recursive call
        if(next != nullptr) head->next = reverseKGroup(next,k);
        
        // Return head of rev list : curr
        return prev;

    }
};

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

bool isCircularList(Node* head){
    if(head == nullptr) return true;
    Node* temp = head->next;
    while(temp != head && temp != nullptr) temp = temp->next;
    if(temp == head) return true;
    return false;
}

int main(){
    
    return 0;
}