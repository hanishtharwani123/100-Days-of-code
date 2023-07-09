// 17. Reverse Nodes in k-Group
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        int count = 0;
        
        // Count the number of nodes in the group
        while (current != nullptr && count < k) {
            current = current->next;
            count++;
        }
        
        // If there are k or more nodes in the group, reverse them
        if (count == k) {
            current = reverseKGroup(current, k); // Recursive call for the remaining nodes
            while (count > 0) {
                ListNode* temp = head->next;
                head->next = current;
                current = head;
                head = temp;
                count--;
            }
            head = current;
        }
        
        return head;
    }
};

// Utility function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    
    for (int i = 0; i < size; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    
    return head;
}

// Utility function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    ListNode* head = createLinkedList(arr, size);
    
    int k = 2;
    
    Solution solution;
    ListNode* reversedHead = solution.reverseKGroup(head, k);
    
    printLinkedList(reversedHead);
    
    return 0;
}
