// ...existing code...
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int rollno;
    string name;
    double cgpa;
    Node* left;
    Node* right;


    Node(int roll, string nam, double cg){
        left = nullptr;
        right = nullptr;
        rollno = roll;
        name = nam;
        cgpa = cg;
    }
};


class BST{
private:
    Node* root;

    void destroy(Node* r){
        if(!r) return;

        destroy(r->left);
        destroy(r->right);

        delete r;
    }
public:

    BST(){
        root = nullptr;
    }

    ~BST() {
        destroy(root);
        root=nullptr;
    }

    bool insert(int roll, string n, double c) {
        
        if (root == nullptr) {
                        Node *newNode = new Node(roll, n, c);

            root = newNode;
            return 1;
        }

        Node *current = root;
        Node *parent = root;

        while (current != nullptr) {
        
            parent = current;
        
            if (current->rollno == roll) return 0;
            if (roll < current->rollno) 
            {
                
                current = current->left;
            }
              else 
            {
                current = current->right;
            }
        }
        bool f=true;
        if (roll < parent->rollno) 
        {
            Node *newNode = new Node(roll, n, c);
            parent->left = newNode;
        }
        else if (roll == parent->rollno) 
        {
            f=false;
        }
        else
        { 
            Node *newNode = new Node(roll, n, c);

            parent->right = newNode;
        }
            return f;
    }

void inOrder()   { inOrderHelper(root); cout << endl; }
void inOrderHelper(Node * r)
{
    if (r == nullptr)
        return;
    inOrderHelper(r->left);
    cout<<r->rollno<<" ";
    inOrderHelper(r->right); 

} 


    bool search(int roll) {
        Node *current = root;
        while (current != nullptr) {
            if (current->rollno == roll) return true;
            current = (roll < current->rollno) ? current->left : current->right;
        }
        return false;
    }

    void menu(){
        int check;

        cout<<"1. Insert a new student\n";
        cout<<"2. Search for student\n";
        cout<<"3. See the list of a students\n";
        cout<<"4. Quit\n";

        cout<<"Enter the number : ";
        cin>>check;

        if(check>4 || check<1){
            cout<<"Enter the valid input : ";
            menu();
        }
        while(check<=4 && check>=1){
            if(check == 1){
                int r;
                string n;
                double c;
                cout<<"Enter rollNo. : ";
                cin>>r;
                cout<<"Enter name of the student : ";
                cin>>n;
                cout<<"Enter cgpa : ";
                cin>>c;

                insert(r,n,c);
                
            }
            if(check == 2){
                int r;
                cout<<"Enter rollNo. to search : ";
                cin>>r;
                cout<<search(r)?cout<<"Not found"<<endl:cout<<" found"<<endl;
            }

            if(check==3){
                inOrder();
                cout<<endl;
            }

            if(check==4){
                break;
            }

            cout<<"Enter the number form the given menu : ";
            cin>>check;
        } 
    }

    void displayinRange(int s,int e)   { inOrderHelper(root,s,e); cout << endl; }
    void inOrderHelper(Node * r, int start, int end)
    {
        if (r == nullptr)
            return;
        inOrderHelper(r->left,start,end);
        if(r->cgpa >start && r->cgpa <end){
            cout<<"Roll No."<<r->rollno<<"  Name : "<<r->name<<" CGPA : "<<r->cgpa<<endl;
        }
        inOrderHelper(r->right,start,end); 

    }
    bool deleteMethod(int node) { return deleteNode(root, node); }


    bool deleteNode(Node*& root, int node) {
        if (root == nullptr) return false;
        if (node < root->rollno) return deleteNode(root->left, node);
        else if (node > root->rollno) return deleteNode(root->right, node);
        else {

            if (root->left == nullptr) {
                Node* temp = root;
                root = root->right;
                delete temp;
                return true;
            } else if (root->right == nullptr) {
                Node* temp = root;
                root = root->left;
                delete temp;
                return true;
            } else {
                Node* succ = findMin(root->right);

                root->rollno = succ->rollno;
                root->name = succ->name;
                root->cgpa = succ->cgpa;

                return deleteNode(root->right, succ->rollno);
            }
        }
    }


    Node* findMin(Node* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }
};

int main()
{
    BST obj;
    cout<<"-----------------Task 1: Insertion and Inorder Traversal-----------------"<<endl;
    obj.insert(1,"umar",3.9);
    obj.insert(2,"farham ahmed",4);
    obj.insert(7,"shahab",2.7);
    obj.insert(2,"husnain",1.1);
    obj.insert(4,"zaid",4.2);
    obj.insert(1,"ali",3.3);
    obj.insert(8,"sipra",2.4);

    cout<<endl;
    obj.inOrder();

    cout<<"-----------------Task 1: Searching Nodes-----------------"<<endl;
    obj.search(0)?cout<<"Not found"<<endl:cout<<" found"<<endl;


    cout<<"-----------------Task 1: Deletion of Node-----------------"<<endl;
    BST ob;
    ob.insert(1,"umar",3.9);
    ob.insert(2,"farham ahmed",4);
    ob.~BST();
    ob.inOrder();

    cout<<"-----------------Task 1: inOrder()-----------------"<<endl;
    cout<<endl;
    obj.inOrder();

    cout<<"-----------------Task 1: menu-function -----------------"<<endl;
    ob.menu();

    cout<<"-----------------Task 1.2: remove-----------------"<<endl;
    obj.deleteMethod(2);
    obj.inOrder();

    cout<<"-----------------Task 1.3: displayinRange-----------------"<<endl;
    obj.displayinRange(2,3);


    return 0;
}
