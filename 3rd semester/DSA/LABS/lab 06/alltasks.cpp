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

        void popatindex(int v){
            if(!head) return;
            Node<T>* t=head;
            Node<T>* pret=head;
            if(v==1){
                head=head->next;
                delete t;
                return;
            }
            int c=1;
            while(t){
                if(c==v){
                    pret->next=t->next;
                    delete t;
                    return ;
                }
                c++;
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


        void display()
        {
            if(head==NULL){
                cout<<"\nlist is empty";
                return; }
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




        bool removeKthNode(int k, int& val)
        {
            if(k<=0 || !head)return false;
            if(k==1){
                val=head->data;
                pop_front();
            }

            Node<T>* t=head->next;
            Node<T>* p=head;
            int c=2;
            while(t){
                if(c==k){
                    //Node<T>* temp = t;
                    val = t->data;
                    p->next=t->next;
                    delete t;
                    cout<<"val = "<<val<<endl;
                    return true;
                }
                c++;
                p=t;
                t=t->next;
            }
            return false;
        }

       void combine(list<T>& first, list<T>& second) {
            if (first.isEmpty() && second.isEmpty()) return;

            if (!first.isEmpty()) {
                head = first.head;
                tail = first.tail;
                
                if (!second.isEmpty()) {
                    tail->next = second.head;
                    tail = second.tail;
                }
            } else if (!second.isEmpty()) {
                head = second.head;
                tail = second.tail;
            }

            this->display();


            first.head = first.tail = nullptr;
            second.head = second.tail = nullptr;
        }

        void shuffleMerge(list<T>& first, list<T>& second)
        {
            if(first.isEmpty() && second.isEmpty()) return;

            if(!first.isEmpty() && !second.isEmpty())
            {
                Node<T>* t1 = first.head;
                Node<T>* t2 = second.head;
                Node<T>* temp = NULL;
                Node<T>* prev = NULL;

                // handle first node
                if(t1)
                {
                    head = t1;
                    temp = head;
                    t1 = t1->next;
                }

                while(t1 || t2)
                {
                    if(t2)
                    {
                        temp->next = t2;
                        temp = temp->next;
                        t2 = t2->next;
                    }

                    if(t1)
                    {
                        temp->next = t1;
                        temp = temp->next;
                        t1 = t1->next;
                    }
                }
                
                this->display();
                tail = temp;

                first.head = NULL;
                first.tail = NULL;
                second.head = NULL;
                second.tail = NULL;
            }
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

        void removeDuplicates()
        {
            if(!head) return;

            Node<T>* t1 = head;
            while(t1)
            {
                Node<T>* t2 = t1->next;
                Node<T>* prev = t1;
                while(t2)
                {
                    if(t1->data == t2->data)
                    {
                        prev->next = t2->next;
                        delete t2;
                        t2 = prev->next;
                    }
                    else
                    {
                        prev = t2;
                        t2 = t2->next;
                    }
                }
                t1 = t1->next;
            }

            this->display();
        }





};

int main()
{
    list<int> l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    l2.push_back(4);
    l2.push_back(5);
    l2.push_back(6);
    l2.push_back(7);
    l2.push_back(8);

    

    cout<<"\n --------------task 1 remove kth Node--------------- \n";
    int a=2;
    cout<<"original list = ";
    l2.display();
    cout<<l2.removeKthNode(4,a)<<endl;
    l2.display();


    list<int> l1;
    list<int> l3;

    l1.push_back(0);
    l1.push_back(0);
    l1.push_back(0);
    l1.push_back(0);
    l1.push_back(0);
    l1.push_back(0);
    l1.push_back(0);
    l1.push_back(0);

    cout<<"\n---------------task 2 Combine-------------- \n";
    l3.combine(l1, l2);

    l1.display();
    l2.display();


    l1.push_back(0);
    l1.push_back(0);
    l1.push_back(0);
    l1.push_back(0);
    l1.push_back(0);
    l1.push_back(0);
    l1.push_back(0);
    l1.push_back(0);

    l2.push_back(1);
    l2.push_back(1);
    l2.push_back(1);
    l2.push_back(1);
    l2.push_back(1);
    l2.push_back(1);
    l2.push_back(1);
    l2.push_back(1);


    cout<<"\n --------------task 3 Shuffle-------------- \n";
    l3.shuffleMerge(l1, l2);

    cout<<"\n --------------task 5 Shuffle-------------- \n";
    l3.removeDuplicates();
    //l3.display();

    cout<<"\n --------------task 4 Shuffle-------------- \n";
    l3.reverse();
    l3.display();


    

    
    
    return 0;
}