//#ifndef circular_doubly_list_H
//#define circular_doubly_list_H

#include <iostream>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() : next(nullptr), prev(nullptr) {}
    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template<typename T>
class list {
public:
    Node<T>* head;
    Node<T>* tail;

    list() : head(nullptr), tail(nullptr) {}

    ~list() {
        while (!isEmpty())
            pop_front();
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void push_front(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            head = tail = newNode;
            head->next = head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            head = tail = newNode;
            head->next = head->prev = head;
        } else {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void insertBefore(T key, T val) {
        if (isEmpty()) return;

        Node<T>* newNode = new Node<T>(val);
        Node<T>* curr = head;
//{ 1 2 3 4 5 6 7 } (2,8);
        do {
            if (curr->data == key) {
                newNode->next = curr;
                newNode->prev = curr->prev;
                curr->prev->next = newNode;
                curr->prev = newNode;

                if (curr == head)
                    head = newNode;
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }
//{ 1 2 3 4 5 6 7 } (2,8);
    void insertAfter(T key, T val) {
        if (isEmpty()) return;

        Node<T>* newNode = new Node<T>(val);
        Node<T>* curr = head;

        do {
            if (curr->data == key) {
                newNode->next = curr->next;
                newNode->prev = curr;
                curr->next->prev = newNode;
                curr->next = newNode;

                if (curr == tail)
                    tail = newNode;
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    void pop_front() {
        if (isEmpty()) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }

    void pop_back() {
        if (isEmpty()) return;

        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }

        Node<T>* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }

    // 1 2 3 4 5 7 2

    void pop(T val) {
        if (isEmpty()) return;

        Node<T>* curr = head;

        do {
            if (curr->data == val) {
                if (curr == head)
                    pop_front();
                else if (curr == tail)
                    pop_back();
                else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                }
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    int search(T val) {
        if (isEmpty()) throw runtime_error("List is empty");

        Node<T>* curr = head;
        int i = 0;

        do {
            if (curr->data == val)
                return i;
            curr = curr->next;
            i++;
        } while (curr != head);

        return -1;
    }

    int countNodes() {
        if (isEmpty()) return 0;

        int count = 0;
        Node<T>* curr = head;
        do {
            count++;
            curr = curr->next;
        } while (curr != head);

        return count;
    }

    void updateNode(T key, T val) {
        if (isEmpty()) throw runtime_error("List is empty");

        Node<T>* curr = head;
        do {
            if (curr->data == key) {
                curr->data = val;
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    void reverse() {
        if (isEmpty()) return;

        Node<T>* curr = head;
        Node<T>* temp = nullptr;

        do {
            temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;
            curr = temp;
        } while (curr != head);

        temp = head;
        head = tail;
        tail = temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "(empty)\n";
            return;
        }

        Node<T>* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void displayReverse() {
        if (isEmpty()) {
            cout << "(empty)\n";
            return;
        }

        Node<T>* temp = tail;
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != tail);
        cout << endl;
    }

    void mergeSortedLists(list<T>& l1, list<T>& l2) {
        if(l1.tail->data<=l2.head->data)
        {
            l1.tail->next = l2.head;
            l2.head->prev = l1.tail;

            l1.tail = l2.tail;
            l1.tail->next = l1.head;

            head=l1.head;
            tail = l1.tail;
            l1.display();

        }

        Node<T>* curr = l1.head;
        Node<T> t=l2.head;
        while(curr!=head)
        {
            
            while(curr->next->data <= t->data && curr!=l1.head){
                curr=curr->next;
            }
            Node<T> 
            curr->next=t;
            t.prev = curr;
            
        }


    }

        /*void mergeSortedLists(list<T>& l1, list<T>& l2) {
        Node<T>* p1 = l1.head;
        Node<T>* p2 = l2.head;

        if (l1.isEmpty() && l2.isEmpty()) return;

        int n1 = l1.countNodes();
        int n2 = l2.countNodes();

        auto detach = [](Node<T>*& node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            Node<T>* temp = node;
            node = node->next;
            temp->next = temp->prev = temp;
            return temp;
        };

        while (n1 > 0 || n2 > 0) {
            Node<T>* selected = nullptr;

            if (n1 > 0 && (n2 == 0 || p1->data <= p2->data)) {
                selected = detach(p1);
                n1--;
            } else {
                selected = detach(p2);
                n2--;
            }

            if (isEmpty()) {
                head = tail = selected;
                head->next = head->prev = head;
            } else {
                selected->prev = tail;
                selected->next = head;
                tail->next = selected;
                head->prev = selected;
                tail = selected;
            }
        }



        l1.head = l1.tail = nullptr;
        l2.head = l2.tail = nullptr;
    }
*/

    void splitList(list<T>& left, list<T>& right) {
        if (isEmpty()) return;

        int total = countNodes();
        int mid = (total + 1) / 2; 

        Node<T>* curr = head;
        for (int i = 1; i < mid; ++i){
            curr = curr->next;
        }

//1 2 3 4 5 6
        left.head = head;
        left.tail = curr;
        


        right.head = curr->next;
        right.tail = tail;

        left.head->prev = left.tail;
        left.tail->next = left.head;

        right.head->prev = right.tail;
        right.tail->next = right.head;


        cout<<"\nLeft List : ";
        left.display();
        cout<<"\nRight List : ";
        right.display();

        head = tail = nullptr;
    }

    void combine(list<T>& left, list<T>& right){
        Node<T>* l1 = left.head;
        Node<T>* l2 = right.head;

        if(!l1 || !l2){
            if(!l2 && !l1)return;
            if(!l2){
                left.display();
                return;
            }
            else{
                right.display();
                return;
            }

        }
            left.tail->next = right.head;
            right.head->prev = left.tail;
            left.tail=right.tail;
            left.tail->next=left.head;

            left.display();
    }


    
};

//#endif


int main()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(5);
    l1.push_back(7);
    l1.push_back(9);
    //l1.push_back(7);
    //l1.push_back(6);
    //l1.push_back(9);


    list<int> l2;
    l2.push_back(2);
    l2.push_back(4);
    l2.push_back(6);
    l2.push_back(8);
    l2.push_back(10);
    //l2.push_back(7);
    //l2.push_back(4);
    //l2.push_back(6);


    cout<<"\n --------------task 1 Merge List--------------- \n";

    list<int> l3;

    l3.mergeSortedLists(l1,l2);


    cout<<"\n --------------task 2 Split List--------------- \n";

    //l2.display();
    list<int> l4;
    list<int> l5;
    //l3.splitList(l4,l5);


    cout<<"\n --------------task 3 combine List--------------- \n";

    l1.display();
    
    l2.display();
    l4.combine(l1,l2);
    

    




    return 0;
}