#include<iostream>
#include<unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Q1 Remove duplicates from sorted LL - leetcode 83
// TC : O(n), SC: O(n)
class sortedDuplicates {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* nxt = nullptr;
        while(temp != nullptr && temp->next != nullptr){
            nxt = temp->next;
            if(temp->val == nxt->val){
                temp->next = nxt->next;
                delete nxt;
            } 
            else temp = temp->next;
        }
        return head;
    }
};

// Q2 Remove duplicates from unsorted list - leetcode
// Method 1 : double transversing
class unsortedDuplicates {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* Pointer1 = head;
        while(Pointer1 != nullptr && Pointer1 -> next != nullptr){
            ListNode* Pointer2 = Pointer1->next;
            ListNode* prev = Pointer1;
            while(Pointer2 != nullptr){
                if(Pointer1->val == Pointer2->val){
                    prev->next = Pointer2->next;
                    ListNode* Todelete = Pointer2;
                    delete Todelete;
                    Pointer2 = prev->next;
                }else{
                    prev = Pointer2;
                    Pointer2 = Pointer2->next;
                } 
            }
            Pointer1 = Pointer1->next;
        }
        return head;
    }
};
// Method 2 : Sort and then above algo
// Method 3 : Using unordered set
class unsortedDuplicates {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> present;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            if(present.find(temp->val) != present.end()){
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            } 
            else{
                present.insert(temp->val);
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};

class DivideList {
public:
    ListNode* DivideListBy2(ListNode* head) {
        int length = 1;
        ListNode* temp = head->next;
        while(temp != head){
            length++;
            temp = temp->next;
        } 
        ListNode* head2 = nullptr;
        for(int i = 1; i <= length; ++i){
            if(i == (length/2)+1){
                head2 = temp->next;
                temp->next = head;
                temp = head2;
            }else if(i == length){
                temp->next = head2;
            }else temp = temp->next;
        }
        return head, head2;
    }
};



int main(){

    return 0;
}