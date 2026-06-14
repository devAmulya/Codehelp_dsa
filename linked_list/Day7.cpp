#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Q : Check Palindrome leetcode 234
// Method 1 : Convert to array and check . TC : O(n), SC: O(n)

class Solution {
private:
    bool checkPalindrome(vector<int>& arr){
        int n = arr.size();
        int i = 0, j = n-1;
        while(i<=j){
            if(arr[i] != arr[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        return checkPalindrome(arr);
    }
};

// Method 2 : Reverse linked list from mid point and compare head & mid and transverse.
// (a) Direct Mid calculation
class Solution {
private:
    int length(ListNode* head){
        int n = 0;
        while(head != nullptr){
            n++;
            head = head->next;
        }
        return n;
    }
public:
    bool isPalindrome(ListNode* head) {
        int mid = length(head)/2;
        // Find middle node
        ListNode* middle = head;
        for(int i = 0; i < mid; ++i) middle=middle->next;
        // Reverse Second half
        ListNode* prev = nullptr;
        ListNode* curr = middle;
        ListNode* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        middle = prev;
        // Compare from middle next
        ListNode* temp = head;
        for(int i = 0; i < mid; ++i){
            if(temp->val != middle->val) return false;
            temp = temp->next;
            middle = middle->next;
        }
        return true;
    }
};

// (b) Using Tortoise and hare method
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next;
        // Reverse Second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        slow = prev;
        // Compare from middle next
        ListNode* temp = head;
        while(temp && slow){
            if(temp->val != slow->val) return false;
            temp = temp->next;
            slow = slow->next;
        }
        return true;
    }
};

int main(){

    return 0;
}