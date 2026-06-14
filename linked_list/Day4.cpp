#include<iostream>
#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class CycleDetect {
public:
    bool hasCycle(ListNode *head) {

        // Method One with use of map or set
        /* unordered_map<ListNode* , bool> marked;
        ListNode* temp = head;
        while(temp != nullptr){
            if(marked.find(temp) != marked.end()) return true;
            marked[temp] = true;
            temp = temp -> next;
        }
        return false; */
        /* unordered_set<ListNode*> marked;
        ListNode* temp = head;
        while(temp != nullptr){
            if(marked.find(temp) != marked.end()) return true;
            // Return temp if start asked
            marked.insert(temp);
            temp = temp -> next;
        }
        return false;
         */

        //  Method 2 : Warshal floyd Cycle detection(slow/fast pointer)
        // Also called Tortoise and Hare Method
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

class CycleStartNode {
public:
    static ListNode *StartCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    };
};

class RemoveCycle {
public:
    ListNode *removeCycle(ListNode *head) {
        // Method 1 : Recieve start node of cycle and use loop
        // Create temp = start->next and loop till temp->next != start, when temp == start mark temp->next = nullptr
        // Method 2 : Keep prev and find start node of cycle, mark prev->next = nullptr

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                ListNode* prev = fast;
                while(slow != fast){
                    prev = fast;
                    slow = slow->next;
                    fast = fast->next;
                }
                cout<<"Start of cycle Node : "<<slow;
                prev->next = nullptr;
            }
        }
        return nullptr;
    }
};