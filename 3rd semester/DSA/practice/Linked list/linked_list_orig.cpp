#include<iostream>
using namespace std;


class Node
{

public:
    int data;
    Node* next;

    Node() 
    {
        next=NULL;
    }

    Node(int a)
    {
        data=a;
        next=NULL;
    }
};

class list
{
    public:
        Node* head;
        Node* tail;

        list()
        {
            head=NULL;
            tail=NULL;
        }


    void push_front(int val)
    {
        Node* newNode = new Node(val);
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

    void push_back(int val)
    {
        Node* newNode = new Node(val);
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

    void pop_front()
    {
        if(head==NULL)
        {
            return;
        }
        else{
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }

    void pop_back()
    {
        if(head==NULL)
        {
            return;
        }
        else{
            Node* temp=head;
            while(temp->next!=tail)
            {
                temp=temp->next;
            }
            temp->next=NULL;
            delete tail;
            tail=temp;
        }
    }

    void display()
    {
        if(head==NULL){return; }
        else{
            Node* temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
    }


};

int main()
{
    list ll;
    ll.push_back(7);
    ll.push_back(6);
    ll.push_back(5);
    ll.push_back(4);

    ll.display();

    return 0;
}
