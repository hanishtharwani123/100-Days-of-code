// 62.  Linked List Cycle II
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        // Check if there's a cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        // If there's no cycle, return nullptr
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        // Move one pointer to the head and keep the other at the meeting point
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

int main() {
    // Create a linked list with a cycle for testing
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle

    Solution solution;
    ListNode *result = solution.detectCycle(head);

    if (result != nullptr) {
        std::cout << "Cycle starts at node with value " << result->val << std::endl;
    } else {
        std::cout << "No cycle found." << std::endl;
    }

    // Don't forget to clean up memory (not included in this example)
    
    return 0;
}
