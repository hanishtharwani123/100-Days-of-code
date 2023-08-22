//59. Copy List with Random Pointer
#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        
        unordered_map<Node*, Node*> nodeMap; // Maps original nodes to their copies
        
        // First pass: Create copies of the nodes and populate the map
        Node* curr = head;
        while (curr) {
            nodeMap[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // Second pass: Update next and random pointers of copied nodes
        curr = head;
        while (curr) {
            nodeMap[curr]->next = nodeMap[curr->next];
            nodeMap[curr]->random = nodeMap[curr->random];
            curr = curr->next;
        }
        
        return nodeMap[head]; // Return the head of the copied linked list
    }
};

// Helper function to print the linked list
void printLinkedList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << "(" << curr->val << ", ";
        if (curr->random) {
            cout << curr->random->val;
        } else {
            cout << "null";
        }
        cout << ") -> ";
        curr = curr->next;
    }
    cout << "null" << endl;
}

int main() {
    // Create the linked list here
    
    // Example: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(1);
    
    head->random = nullptr;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head;
    
    Solution solution;
    Node* copiedHead = solution.copyRandomList(head);
    
    cout << "Original Linked List:" << endl;
    printLinkedList(head);
    
    cout << "Copied Linked List:" << endl;
    printLinkedList(copiedHead);
    
    return 0;
}
