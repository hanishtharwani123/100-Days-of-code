// 68. Intersection of Two Linked Lists
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;

        while (ptrA != ptrB) {
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }

        return ptrA;
    }
};

int main() {
    // Create nodes for the linked lists
    ListNode *node8 = new ListNode(8);
    ListNode *node4 = new ListNode(4);
    ListNode *node1 = new ListNode(1);

    ListNode *listA = new ListNode(4);
    listA->next = node1;
    node1->next = node8;
    node8->next = node4;

    ListNode *listB = new ListNode(5);
    listB->next = new ListNode(6);
    listB->next->next = new ListNode(1);
    listB->next->next->next = node8; // Intersection point

    Solution solution;
    ListNode *intersectionNode = solution.getIntersectionNode(listA, listB);

    if (intersectionNode) {
        cout << "Intersected at " << intersectionNode->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    // Clean up memory (optional, but recommended)
    delete listA;
    delete listB;

    return 0;
}
