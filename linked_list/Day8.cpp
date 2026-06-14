#include<iostream>
using namespace std;

// Q : Leetcode 2 - Add Two Number
// Given in reverse order in form of Linked List

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* temp = head;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val+l2->val+carry;
            carry = sum/10;
            sum %= 10;
            ListNode* curr = new ListNode(sum);
            temp->next = curr;
            temp = curr;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* curr = l1 ? l1 : l2;
        while(carry != 0){
            if(curr){
                int sum = curr->val + carry;
                carry = sum/10;
                sum %= 10;
                ListNode* newNode = new ListNode(sum);
                temp->next = newNode;
                temp = newNode;
                curr = curr->next;
            }
            else{
                ListNode* newNode = new ListNode(carry);
                temp->next = newNode;
                temp = newNode;
                carry = 0;
            }
        }
        temp->next = curr;
        return head->next;
    }
};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* temp = &dummy;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;
        }
        return dummy.next;
    }
};

// Q2 : Adding One to a linked list
/* Method : 
(i) if not reverse, reverse it now
(ii) Add one to first node and generate carry and keep adding till 
carry == 0
(iii) reverse again if not reversed asked. 
*/