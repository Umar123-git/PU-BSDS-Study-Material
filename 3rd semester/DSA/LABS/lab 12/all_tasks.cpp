#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    int h,bf;
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

    void preOrder() { preOrderHelper(root); cout << endl; }
    void preOrderHelper(Node* p) {
        if (!p) return;
        cout << p->data << " ";
        preOrderHelper(p->left);
        preOrderHelper(p->right);
    }

    void postOrder() { postOrderHelper(root); cout << endl; }
    void postOrderHelper(Node* p) {
        if (!p) return;
        postOrderHelper(p->left);
        postOrderHelper(p->right);
        cout << p->data << " ";
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


    int indexOf(const vector<int>& arr, int l, int r, const int& val) {
        for (int i = l; i <= r; ++i) if (arr[i] == val) return i;
        return -1;
    }

    Node* buildInPostHelper(const vector<int>& in, int inL, int inR,
                            const vector<int>& post, int postL, int postR) {
        if (postL > postR || inL > inR) return nullptr;
        int rootVal = post[postR];
        Node* node = new Node(rootVal);
        int idx = indexOf(in, inL, inR, rootVal);
        if (idx == -1) return node;
        int leftSize = idx - inL;
        node->left  = buildInPostHelper(in, inL, idx-1, post, postL, postL+leftSize-1);
        node->right = buildInPostHelper(in, idx+1, inR, post, postL+leftSize, postR-1);
        return node;
    }

    void construct_from_traversals(const vector<int>& inorder, const vector<int>& postorder) {
        if (inorder.size() != postorder.size()) {
            root = nullptr;
            return;
        }
        root = buildInPostHelper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
 


    //void insert(int node){
    //    root = insert(root, node);
    //}

    
    int height(Node* r){
        return r ? r->h : -1;
    }

    void updateNode(Node* r){
        if (!r) return;
        r->h = 1 + max(height(r->left), height(r->right));
        r->bf = height(r->left) - height(r->right);
    }

    Node* llr(Node* gp){
        cout << "Performing LL rotation on " << gp->data << endl;
        Node* parent = gp->left;
        Node* temp = parent->right;
        parent->right = gp;
        gp->left = temp;

       
        updateNode(gp);
        updateNode(parent);

        return parent; 
    }

    Node* rrr(Node* gp){
        cout << "Performing RR rotation on " << gp->data << endl;
        Node* parent = gp->right;
        Node* temp = parent->left;
        parent->left = gp;
        gp->right = temp;

        
        updateNode(gp);
        updateNode(parent);
        
        return parent; 
    }




    Node* insert(Node* r, int node){

        if(!r){
            return new Node(node);
        }

        // Recursive insertion
        if(node < r->data){
            r->left = insert(r->left, node);
        } else {
            r->right = insert(r->right, node);
        }
        

        updateNode(r);

        // Rebalancing logic
        // Left Heavy
        if(r->bf > 1){
            // LL case
            if(node < r->left->data){
                return llr(r);
            }
            // LR case
            else {
                cout << "Performing LR rotation on " << r->data << endl;
                r->left = rrr(r->left);
                return llr(r);
            }
        }
        // Right Heavy
        else if(r->bf < -1){
            // RR case
            if(node > r->right->data){
                return rrr(r);
            }
            // RL case
            else {
                cout << "Performing RL rotation on " << r->data << endl;
                r->right = llr(r->right);
                return rrr(r);
            }
        }
        
        
        return r;
    }




    void createBalancedTree(int arr[], int l, int r) {
        if (l > r) {
            return ;
        }

        
        int mid = (l + r ) / 2;

        insert(arr[mid]);

        //Node* node = insert(arr[mid]);

         createBalancedTree(arr, l, mid - 1);

        
        createBalancedTree(arr, mid + 1, r);

    
    }

    void createBackbone(Node* r){
        if(!r)return;

        Node* temp = root;
        while(!temp){
            if(temp->left){
                Node* rotated = rrr(temp);
                temp = rotated;
                root = rotated;
            }
            temp = temp->right;
        }
    }




};


int main() 
{
    cout<<"------------Task 1--------------\n";
    BST bst;
    vector<int> in1 = {1, 2, 3, 4, 5, 6};
    vector<int> pre1 = {3, 1, 2, 5, 4, 6};
    bst.construct_from_traversals(pre1, in1);
    cout << "In-order traversal (Example 1): ";
    bst.inOrder();
    cout << "Post-order traversal (Example 1): ";
    bst.postOrder();
    BST bst2;
    vector<int> in2 = {5,10,15,25,27,30,35,40,45,50,52,55,60,65,70,75,80,85,90,100};
    vector<int> pre2 = {50,25,10,5,15,40,30,27,35,45,75,60,55,52,65,70,90,80,85,100};
    bst2.construct_from_traversals(pre2,in2);
    cout << "\nIn-order traversal (Example 2): ";
    bst2.inOrder();
    cout << "Post-order traversal (Example 2): ";
    bst2.postOrder();




    cout<<"\n------------Task 2--------------\n";


    BST bst1;
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    bst1.createBalancedTree(arr, 0, n - 1);
    cout << "Pre-order: ";
    bst1.preOrder();
    cout << "In-order: ";
    bst1.inOrder();
    cout << "Post-order: ";
    bst1.postOrder();
    return 0;




    cout<<"--------------Task 3 ------------------";
    BST temp;

    //temp.createBackbone();


}




    
