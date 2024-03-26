//
// Created by kayxhding on 2024-03-23 11:19:31
//
//
/*
Design a data structure that follows the constraints of a Least Recently Used
(LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return
-1. void put(int key, int value) Update the value of the key if the key exists.
Otherwise, add the key-value pair to the cache. If the number of keys exceeds
the capacity from this operation, evict the least recently used key. The
functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    Node* prev = nullptr;
    Node* next = nullptr;
    int key = -1;
    int value = -1;
    Node(int key = -1, int value = -1) : key(key), value(value) {}
};

/*
时间复杂度：所有操作均为 O(1)。
空间复杂度：O(min(p,capacity))，其中 p 为 put 的调用次数。
*/

class LRUCache {
  public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node()) {
        dummy->prev = dummy;
        dummy->next = dummy;
    }

    int get(int key) {
        auto node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value) {
        auto node = get_node(key);
        if (node != nullptr) {
            node->value = value;
            return;
        }

        node = new Node(key, value);
        push_front(node);
        key_to_node[key] = node;
        if (key_to_node.size() > capacity) {
            auto back_node = dummy->prev;
            key_to_node.erase(back_node->key);
            remove(back_node);
            delete back_node;
        }

        return;
    }

    void printCache() {
        for (auto it = key_to_node.begin(); it != key_to_node.end(); ++it) {
            std::cout << " key: " << it->first
                      << " ,value: " << it->second->value;
        }
        std::cout << endl;
    }

    void printList() {
        Node* head = dummy->next;
        while (head && head != dummy) {
            std::cout << " key: " << head->key << " ,value: " << head->value;
            head = head->next;
        }
        std::cout << endl;
    }

  private:
    void push_front(Node* x) {
        x->prev = dummy;
        x->next = dummy->next;
        x->next->prev = x;
        x->prev->next = x;
    }

    void remove(Node* x) {
        x->next->prev = x->prev;
        x->prev->next = x->next;
    }

    Node* get_node(int key) {
        auto it = key_to_node.find(key);
        if (it == key_to_node.end()) {
            return nullptr;
        }

        remove(it->second);
        push_front(it->second);
        return it->second;
    }

  private:
    int capacity;
    Node* dummy;
    unordered_map<int, Node*> key_to_node;
};

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);  // cache is {1=1}
    lRUCache.printList();
    lRUCache.put(2, 2);  // cache is {1=1, 2=2}
    lRUCache.printList();
    lRUCache.get(1);  // return 1
    lRUCache.printList();
    lRUCache.put(3, 3);  // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.printList();
    lRUCache.get(2);  // returns -1 (not found)
    lRUCache.printList();
    lRUCache.put(4, 4);  // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.printList();
    lRUCache.get(1);  // return -1 (not found)
    lRUCache.printList();
    lRUCache.get(3);  // return 3
    lRUCache.printList();
    lRUCache.get(4);  // return 4
    lRUCache.printList();
}
