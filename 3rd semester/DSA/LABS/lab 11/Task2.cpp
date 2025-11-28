
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


class BST{
private:

    Node *root;

    bool recsearch(Node* r, int n){
        if(!r)return 0;

        if(r->data == n)return true;

        return (recsearch(r->left,n) || recsearch(r->right,n));
    }

    int countNodes(Node* r){
        if(!r)return 0;
        return 1+countNodes(r->left)+countNodes(r->right);
    }

    int getheight(Node* r){
        if(!r)return 0;
        int leftH = getheight(r->left);
        int rightH = getheight(r->right);
        return 1+max(leftH,rightH);
    }
public:
   

    BST(){
        root = nullptr;
    }

   // ~BST() {
   //     deleteTree(root);
   // }

    void insert(int node) {
        Node *newNode = new Node(node);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (node < current->data) current = current->left;
            else current = current->right;
        }

        if (node < parent->data) parent->left = newNode;
        else parent->right = newNode;
    }


    bool recsearch(int roll) {
        
        return recsearch(root,roll);
    }

    void inOrder()   { inOrderHelper(root); cout << endl; }
    void inOrderHelper(Node * r)
    {
        if (r == nullptr)
            return;
        inOrderHelper(r->left);
        cout<<r->data<<" ";
        inOrderHelper(r->right); 

    }

    int countNodes(){
        return countNodes(root);
    }
    
    int getheight(){
        return getheight(root);
    }

    void doubletree(){
        doubletree(root);
    }

    void doubletree(Node* r){
        if(!r)return;

        doubletree(r->left);
        doubletree(r->right);

        Node* newNode = new Node(r->data);
        newNode->left = r->left;
        r->left = newNode;
    }

    void root_to_leaf_paths(){
        vector<int> path;
        root_to_leaf_paths(root, path);
    }

    void root_to_leaf_paths(Node* r, vector<int>& path){
        if(!r)return;

        path.push_back(r->data);

        if(!r->left && !r->right){
            for(int i=0 ; i<path.size() ; i++){
                if(i!=0)cout<<"->"<<path[i]<<" ";
                else cout<<path[i]<<" ";
            }
            cout<<endl;
        }
        else{
            root_to_leaf_paths(r->left, path);
            root_to_leaf_paths(r->right, path);
        }

        path.pop_back();
    }


};


int main()
{
    BST obj;
    obj.insert(50);
    obj.insert(40);
    obj.insert(25);
    obj.insert(75);
    obj.insert(65);
    obj.insert(80);
    //obj.insert(8);

    obj.inOrder();
    cout<<"-----------------Task 2.1: Recursive Search-----------------"<<endl;
    int num;
    cout<<"Enter number to be searched: ";
    cin>>num;
    if(obj.recsearch(num)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }


    cout<<"-----------------Task 2.2: Count Nodes-----------------"<<endl;
    cout<<"Total number of nodes in the tree: "<<obj.countNodes()<<endl;


    cout<<"-----------------Task 2.3: Height of Tree-----------------"<<endl;
    cout<<"Height of the tree is: "<<obj.getheight()<<endl;


    cout<<"-----------------Task 2.4: Double Tree-----------------"<<endl;
    obj.doubletree();
    obj.inOrder();


    cout<<"-----------------Root to leaf paths-----------------"<<endl;
    obj.root_to_leaf_paths();


    return 0;
}
