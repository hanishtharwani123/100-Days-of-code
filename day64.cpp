// 64. Sort List
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head; // Base case: empty list or single element, already sorted
        }

        // Find the middle of the linked list
        ListNode* middle = findMiddle(head);

        // Split the linked list into two halves
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;

        // Recursively sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge the sorted halves
        return merge(left, right);
    }

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        if (left) {
            current->next = left;
        }

        if (right) {
            current->next = right;
        }

        return dummy.next;
    }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution solution;
    ListNode* sortedList = solution.sortList(head);

    // Print the sorted list
    ListNode* current = sortedList;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Clean up memory (free allocated nodes)
    while (sortedList) {
        ListNode* temp = sortedList;
        sortedList = sortedList->next;
        delete temp;
    }

    return 0;
}
