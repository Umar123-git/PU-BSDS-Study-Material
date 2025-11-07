#ifndef CDLL_H
#define CDLL_H

#include <iostream>
#include <stdexcept>
using namespace std;

// Circular Doubly Linked List Node
template <class T>
class CDNode {
public:
    T info;
    CDNode<T>* prev;
    CDNode<T>* next;
    CDNode() : info(), prev(nullptr), next(nullptr) {}
    CDNode(T val) : info(val), prev(nullptr), next(nullptr) {}
};

// Circular Doubly Linked List
template <class T>
class CDLL {
private:
    CDNode<T>* head;
    CDNode<T>* tail;

public:
    CDLL() : head(nullptr), tail(nullptr) {}

    // ===========================
    // Insertion Functions
    // ===========================
    void insertAtHead(T val) {
        CDNode<T>* n = new CDNode<T>(val);
        if (!head) {
            head = tail = n;
            n->next = n->prev = n;
            return;
        }
        n->next = head;
        n->prev = tail;
        head->prev = n;
        tail->next = n;
        head = n;
    }

    void insertAtTail(T val) {
        CDNode<T>* n = new CDNode<T>(val);
        if (!head) {
            head = tail = n;
            n->next = n->prev = n;
            return;
        }
        n->prev = tail;
        n->next = head;
        tail->next = n;
        head->prev = n;
        tail = n;
    }

    void insertBefore(T key, T val) {
        if (!head) return;
        if (head->info == key) { insertAtHead(val); return; }
        CDNode<T>* curr = head->next;
        while (curr != head) {
            if (curr->info == key) {
                CDNode<T>* n = new CDNode<T>(val);
                n->prev = curr->prev;
                n->next = curr;
                curr->prev->next = n;
                curr->prev = n;
                return;
            }
            curr = curr->next;
        }
    }

    void insertAfter(T key, T val) {
        if (!head) { insertAtHead(val); return; }
        CDNode<T>* curr = head;
        do {
            if (curr->info == key) {
                if (curr == tail) { insertAtTail(val); }
                else {
                    CDNode<T>* n = new CDNode<T>(val);
                    n->next = curr->next;
                    n->prev = curr;
                    curr->next->prev = n;
                    curr->next = n;
                }
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    // ===========================
    // Deletion Functions
    // ===========================
    void removeAtHead() {
        if (!head) return;
        if (head == tail) { delete head; head = tail = nullptr; return; }
        CDNode<T>* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }

    void removeAtTail() {
        if (!head) return;
        if (head == tail) { delete head; head = tail = nullptr; return; }
        CDNode<T>* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }

    void remove(T val) {
        if (!head) return;
        if (head->info == val) { removeAtHead(); return; }
        if (tail->info == val) { removeAtTail(); return; }
        CDNode<T>* curr = head->next;
        while (curr != head) {
            if (curr->info == val) {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                delete curr;
                return;
            }
            curr = curr->next;
        }
    }

    void removeBefore(T val) {
        if (!head || head == tail) return;
        if (head->info == val) return; // define 'before head' as no-op
        CDNode<T>* curr = head->next;
        while (curr != head) {
            if (curr->info == val) {
                CDNode<T>* target = curr->prev;
                if (target == head) { removeAtHead(); }
                else if (target == tail) { removeAtTail(); }
                else {
                    target->prev->next = curr;
                    curr->prev = target->prev;
                    delete target;
                }
                return;
            }
            curr = curr->next;
        }
    }

    void removeAfter(T val) {
        if (!head) return;
        CDNode<T>* curr = head;
        do {
            if (curr->info == val) {
                CDNode<T>* target = curr->next;
                if (target == head) { removeAtHead(); }
                else if (target == tail) { removeAtTail(); }
                else {
                    curr->next = target->next;
                    target->next->prev = curr;
                    delete target;
                }
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    // ===========================
    // Utility Functions
    // ===========================
    int search(T key) {
        if (!head) return 0;
        CDNode<T>* curr = head;
        do { if (curr->info == key) return 1; curr = curr->next; } while (curr != head);
        return 0;
    }

    void update(T key, T val) {
        if (!head) return;
        CDNode<T>* curr = head;
        do { if (curr->info == key) { curr->info = val; return; } curr = curr->next; } while (curr != head);
    }

    int countNodes() {
        if (!head) return 0;
        int cnt = 0;
        CDNode<T>* curr = head;
        do { ++cnt; curr = curr->next; } while (curr != head);
        return cnt;
    }

    void display() {
        if (!head) { cout << endl; return; }
        CDNode<T>* curr = head;
        do { cout << curr->info << " "; curr = curr->next; } while (curr != head);
        cout << endl;
    }

    void reverse_display() {
        if (!head) { cout << endl; return; }
        CDNode<T>* curr = tail;
        do { cout << curr->info << " "; curr = curr->prev; } while (curr != tail);
        cout << endl;
    }

    // ===========================
    // Reverse Entire List
    // ===========================
    void reverseList() {
        if (!head || head == tail) return;
        CDNode<T>* curr = head;
        do {
            CDNode<T>* tmp = curr->next;
            curr->next = curr->prev;
            curr->prev = tmp;
            curr = tmp;
        } while (curr != head);
        // swap head and tail
        CDNode<T>* tmp = head; head = tail; tail = tmp;
    }

    // ===========================
    // Find Middle Node
    // ===========================
    CDNode<T>* getMiddleNode() {
        if (!head) return nullptr;
        CDNode<T>* slow = head;
        CDNode<T>* fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Palindrome Check (two-pointer from both ends)
    bool isPalindrome() {
        if (!head || head == tail) return true;
        CDNode<T>* left = head;
        CDNode<T>* right = tail;
        while (left != right && right->next != left) {
            if (left->info != right->info) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    // ===========================
    // Remove Duplicates (Sorted)
    // ===========================
    void removeDuplicatesSorted() {
        if (!head) return;
        CDNode<T>* curr = head;
        do {
            while (curr->next != head && curr->info == curr->next->info) {
                CDNode<T>* dup = curr->next;
                curr->next = dup->next;
                dup->next->prev = curr;
                if (dup == tail) tail = curr;
                delete dup;
            }
            curr = curr->next;
        } while (curr != head);
    }

    // ===========================
    // Remove Duplicates (Unsorted)
    // ===========================
    void removeDuplicatesUnsorted() {
        if (!head) return;
        CDNode<T>* curr = head;
        do {
            CDNode<T>* runner = curr->next;
            while (runner != head) {
                if (runner->info == curr->info) {
                    CDNode<T>* del = runner;
                    runner = runner->next;
                    del->prev->next = del->next;
                    del->next->prev = del->prev;
                    if (del == tail) tail = del->prev;
                    delete del;
                } else {
                    runner = runner->next;
                }
            }
            curr = curr->next;
        } while (curr != head);
    }

    // ===========================
    // Merge Two Sorted Lists (Static)
    // ===========================
    static CDLL<T> mergeSortedLists(CDLL<T>& l1, CDLL<T>& l2) {
        CDLL<T> res;
        int n1 = l1.countNodes();
        int n2 = l2.countNodes();
        CDNode<T>* p1 = l1.head;
        CDNode<T>* p2 = l2.head;
        int i1 = 0, i2 = 0;
        while ((p1 && i1 < n1) || (p2 && i2 < n2)) {
            if (p2 == nullptr || i2 >= n2 || (p1 && i1 < n1 && p1->info <= p2->info)) {
                res.insertAtTail(p1->info); p1 = p1->next; ++i1;
            } else {
                res.insertAtTail(p2->info); p2 = p2->next; ++i2;
            }
        }
        return res;
    }

    // ===========================
    // Extras for parity
    // ===========================
    CDLL<T>* reverselist() {
        CDLL<T>* r = new CDLL<T>();
        if (!head) return r;
        CDNode<T>* curr = head;
        do { r->insertAtHead(curr->info); curr = curr->next; } while (curr != head);
        return r;
    }

    void removeKthNode(int k) {
        if (k <= 0 || !head) return;
        if (k == 1) { removeAtHead(); return; }
        int n = countNodes();
        if (k > n) return;
        CDNode<T>* curr = head;
        for (int i = 1; i < k; ++i) curr = curr->next;
        if (curr == head) { removeAtHead(); return; }
        if (curr == tail) { removeAtTail(); return; }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }

    void removeDuplicates() { removeDuplicatesUnsorted(); }

    void merge(CDLL<T>& other) {
        if (!other.head) return;
        if (!head) { head = other.head; tail = other.tail; other.head = other.tail = nullptr; return; }
        // connect circles
        tail->next = other.head;
        other.head->prev = tail;
        other.tail->next = head;
        head->prev = other.tail;
        tail = other.tail;
        other.head = other.tail = nullptr;
    }

    void swapNodes(T v1, T v2) {
        if (v1 == v2 || !head) return;
        CDNode<T>* n1 = nullptr; CDNode<T>* n2 = nullptr;
        CDNode<T>* curr = head;
        do { if (curr->info == v1) n1 = curr; if (curr->info == v2) n2 = curr; curr = curr->next; } while (curr != head && (!n1 || !n2));
        if (!n1 || !n2) return;
        T t = n1->info; n1->info = n2->info; n2->info = t;
    }

    void sort() {
        if (!head || head == tail) return;
        bool swapped;
        do {
            swapped = false;
            CDNode<T>* curr = head;
            do {
                CDNode<T>* nxt = curr->next;
                if (curr != nxt && curr->info > nxt->info) { T t = curr->info; curr->info = nxt->info; nxt->info = t; swapped = true; }
                curr = curr->next;
            } while (curr != head);
        } while (swapped);
    }

    T findMiddle() {
        if (!head) throw std::runtime_error("List is empty");
        CDNode<T>* mid = getMiddleNode();
        return mid->info;
    }

    CDNode<T>* getTail() { return tail; }

    // ===========================
    // Destructor
    // ===========================
    ~CDLL() {
        if (!head) return;
        // break circle
        tail->next = nullptr;
        CDNode<T>* curr = head;
        while (curr) {
            CDNode<T>* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
        head = tail = nullptr;
    }
};

#endif
