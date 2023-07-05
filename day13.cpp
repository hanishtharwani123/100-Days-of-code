// 13. Merge Two Sorted Lists
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1); // Dummy node to simplify merging
        ListNode* current = dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        // Append any remaining nodes from list1 or list2
        if (list1) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return dummy->next;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedListFromArray(const int arr[], int n) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        ListNode* newNode = new ListNode(arr[i]);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    Solution solution;
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    ListNode* list1 = createLinkedListFromArray(arr1, 3);
    ListNode* list2 = createLinkedListFromArray(arr2, 3);

    std::cout << "List 1: ";
    printLinkedList(list1);

    std::cout << "List 2: ";
    printLinkedList(list2);

    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    std::cout << "Merged List: ";
    printLinkedList(mergedList);

    // Clean up memory (optional, but recommended)
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
