// 63. LRU Cache
#include <iostream>
#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void moveToFront(Node* node) {
        if (node == head) {
            return;
        }
        if (node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->next = head;
        head->prev = node;
        node->prev = nullptr;
        head = node;
    }

    void removeTail() {
        if (tail == nullptr) {
            return;
        }
        if (tail == head) {
            cache.erase(tail->key);
            delete tail;
            head = nullptr;
            tail = nullptr;
        } else {
            cache.erase(tail->key);
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            moveToFront(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            if (cache.size() >= capacity) {
                removeTail();
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl; // Output: 1
    cache.put(3, 3);
    std::cout << cache.get(2) << std::endl; // Output: -1
    cache.put(4, 4);
    std::cout << cache.get(1) << std::endl; // Output: -1
    std::cout << cache.get(3) << std::endl; // Output: 3
    std::cout << cache.get(4) << std::endl; // Output: 4
    return 0;
}
