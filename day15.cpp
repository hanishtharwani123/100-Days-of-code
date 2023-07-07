// 15.  Merge k Sorted Lists
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        
        int interval = 1;
        int n = lists.size();
        
        while (interval < n) {
            for (int i = 0; i < n - interval; i += interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        
        if (l1) {
            current->next = l1;
        } else {
            current->next = l2;
        }
        
        return dummy.next;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(vector<int> values) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    
    return dummy.next;
}

// Helper function to print the elements of a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    
    cout << endl;
}

int main() {
    Solution solution;
    
    // Example case
    vector<vector<int>> lists = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> linkedLists;
    
    for (const auto& list : lists) {
        linkedLists.push_back(createLinkedList(list));
    }
    
    ListNode* mergedList = solution.mergeKLists(linkedLists);
    printLinkedList(mergedList);
    
    return 0;
}
