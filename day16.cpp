// 16. Swap Nodes in Pairs
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // Base case: empty list or single node
        }

        // Nodes to be swapped
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;

        // Swapping
        firstNode->next = swapPairs(secondNode->next);
        secondNode->next = firstNode;

        return secondNode; // New head after swapping
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* curr = dummyHead;
    for (int i = 0; i < size; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return dummyHead->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 1, 2, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createLinkedList(arr, size);
    std::cout << "Original linked list: ";
    printLinkedList(head);

    Solution solution;
    ListNode* newHead = solution.swapPairs(head);
    std::cout << "Modified linked list: ";
    printLinkedList(newHead);

    return 0;
}
