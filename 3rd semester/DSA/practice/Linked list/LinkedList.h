#ifndef list_Node_H
#define list_Node_H

#include<iostream>
using namespace std;

template<typename T>
class Node
{

public:
    T data;
    Node<T>* next;

    Node() 
    {
        next=NULL;
    }

    Node(T a)
    {
        data=a;
        next=NULL;
    }
};

template<typename T>
class list
{
    public:
        Node<T>* head;
        Node<T>* tail;

        list()
        {
            head=NULL;
            tail=NULL;
        }

        ~list() {
            while (head) {
                pop_front(); 
            }
        }


        void push_front(T val)
        {
            Node<T>* newNode = new Node<T>(val);
            if(head==NULL)
            {
                head=tail=newNode;
                return;
            }
            else
            {
                newNode->next=head;
                head = newNode;
            }

        }

        void push_back(T val)
        {
            Node<T>* newNode = new Node<T>(val);
            if(head==NULL)
            {
                head=tail=newNode;
                return;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        void insertBefore(T key , T v)
        {
            Node<T>* newNode = new Node<T>(v);
            if(!head){
                head=tail=newNode;
                return ;
            }
            if(head->data == key){
                newNode->next = head;
                head = newNode;
                return;
            }

            Node<T>* temp = head;
            while(temp->next){
                if(temp->next->data==key){
                    newNode->next = temp->next;
                    temp->next=newNode;
                    return;
                }
                temp=temp->next;
            }

        }

        void insertAfter(T key , T v)
        {
            Node<T>* newNode = new Node<T>(v);
            if(!head){
                head=tail=newNode;
                return ;
            }
            Node<T>* temp = head;
            while(temp){
                if(temp->data==key){
                    newNode->next = temp->next;
                    temp->next=newNode;
                    if(temp == tail)tail=newNode;
                    return;
                }
                temp=temp->next;
            }

        }

        void pop_front()
        {
            if(head==NULL)
            {
                return;
            }
            else{
                Node<T>* temp=head;
                head=head->next;
                temp->next=NULL;
                delete temp;
                if (!head) tail = nullptr;
            }
        }

        void pop_back()
        {
            if(head==NULL)
            {
                return;
            }
            if (head == tail) {
                delete head;
                head = tail = nullptr;
                return;
            }
            else{
                Node<T>* temp=head;
                while(temp->next!=tail)
                {
                    temp=temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
        }

        void pop(T v){
            if(!head) return;
            Node<T>* t=head;
            Node<T>* pret=head;
            if(head->data==v){
                head=head->next;
                delete t;
                return;
            }

            while(t){
                if(t->data==v){
                    pret->next=t->next;
                    delete t;
                    return ;
                }
                pret=t;
                t=t->next;
            }
        }

        void popBefore(T v){
            if(!head || head->data==v || head->next==NULL) return;

            Node<T>* prev = nullptr;
            Node<T>* curr = head;

            while(curr->next){
                if(curr->next->data == v){
                    if(prev == nullptr) pop_front();
                    else {
                        prev->next = curr->next;
                        delete curr;
                    }
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
        }

        void popAfter(T v){
            if(!head) return;
            Node<T>* t=head;
            while(t){
                if(t->data==v && t->next){
                    Node<T>* f=t->next;
                    t->next = f->next;
                    if(f==tail)tail=t;
                    delete f;
                    return;
                }
                t=t->next;
            }
        }

        int search(T v){
            if(!head)throw runtime_error("LinkedList is empty");
            int i=0;
            Node<T>* t=head;
            while(t){
                if(t->data==v)return i;
                i++;
                t=t->next;
            }
            //cout<<"\nNode not found ";
            return -1;
        }

        int countNodes(){
            int i=0;
            Node<T>* t=head;
            while(t){
                i++;
                t=t->next;
            }
            return i;
        }

        void updateNode(T key, T v){
            if(!head)throw runtime_error("LinkedList is empty");
            Node<T>* t=head;
            while(t){
                if(t->data==key) {
                    t->data = v;
                    return;
                }
                t= t->next;
            }
        }

        bool isEmpty() const {
            return head == nullptr;
        }

        void reverse() {
            Node<T>* prev = nullptr;
            Node<T>* curr = head;
            Node<T>* next = nullptr;
            tail = head;
            while (curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }



        void display()
        {
            if(head==NULL){return; }
            else{
                Node<T>* temp=head;
                while(temp!=NULL)
                {
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
                cout<<endl;
            }
        }


};
#endif