#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Node
{
public:
    T data;
    int h, bf;

    Node<T>* left;
    Node<T>* right;
    Node(T value) : data(value), left(nullptr), right(nullptr), h(0), bf(0) {}
};

template<class T>
class BST{
public:
    Node<T> *root;

    BST(){
        root = nullptr;
    }

    BST(T value){
        root = new Node<T>(value);
    }

    ~BST() {
        deleteTree(root);
    }

/*    void insert(T node) {
        Node<T> *newNode = new Node<T>(node);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node<T> *current = root;
        Node<T> *parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (node < current->data) current = current->left;
            else current = current->right;
        }

        if (node < parent->data) parent->left = newNode;
        else parent->right = newNode;
    }
*/
    void insert(T node){
        root = insert(root, node);
    }

    // Helper function to get height safely (returns -1 for nullptr)
    int height(Node<T>* r){
        return r ? r->h : -1;
    }

    // Helper function to update height and balance factor
    void updateNode(Node<T>* r){
        if (!r) return;
        r->h = 1 + max(height(r->left), height(r->right));
        r->bf = height(r->left) - height(r->right);
    }

    Node<T>* llr(Node<T>* gp){
        cout << "Performing LL rotation on " << gp->data << endl;
        Node<T>* parent = gp->left;
        Node<T>* temp = parent->right;
        parent->right = gp;
        gp->left = temp;

        // Update heights and BFs of the modified nodes (grandparent first, then new parent)
        updateNode(gp);
        updateNode(parent);

        return parent; // Return the new root of this subtree
    }

    Node<T>* rrr(Node<T>* gp){
        cout << "Performing RR rotation on " << gp->data << endl;
        Node<T>* parent = gp->right;
        Node<T>* temp = parent->left;
        parent->left = gp;
        gp->right = temp;

        // Update heights and BFs of the modified nodes (grandparent first, then new parent)
        updateNode(gp);
        updateNode(parent);
        
        return parent; // Return the new root of this subtree
    }

    Node<T>* insert(Node<T>* r, T node){

        if(!r){
            return new Node<T>(node);
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
        
        // If no rotation was needed, return the original node pointer
        return r;
    }

    void inOrder()   { inOrderHelper(root); cout << endl; }
    void preOrder()  { preOrderHelper(root); cout << endl; }
    void postOrder() { postOrderHelper(root); cout << endl; }

    void inOrderHelper(Node<T> *p) {
        if (!p) return;
        inOrderHelper(p->left);
        cout << "(" << p->data << "," << p->h << "," << p->bf << ") ";
        inOrderHelper(p->right);
    }

    void preOrderHelper(Node<T> *p) {
        if (!p) return;
        cout << "(" << p->data << "," << p->h << "," << p->bf << ") ";
        preOrderHelper(p->left);
        preOrderHelper(p->right);
    }

    void postOrderHelper(Node<T> *p) {
        if (!p) return;
        postOrderHelper(p->left);
        postOrderHelper(p->right);
        cout << "(" << p->data << "," << p->h << "," << p->bf << ") ";
    }

    void deleteMethod(T node) { root = deleteNode(root, node); }

    bool search(T node) {
        Node<T> *current = root;
        while (current != nullptr) {
            if (current->data == node) return true;
            current = (node < current->data) ? current->left : current->right;
        }
        return false;
    }


    void deleteTree(Node<T>* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    Node<T>* deleteNode(Node<T>* root, T node) {
        if (root == nullptr) return root;
        if (node < root->data) root->left = deleteNode(root->left, node);
        else if (node > root->data) root->right = deleteNode(root->right, node);
        else {
            if (root->left == nullptr) {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }
            Node<T>* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

    

/*  

    // Build tree from preorder + inorder (simple linear index search)
    void buildFromPreIn(const vector<T>& preorder, const vector<T>& inorder) {
        if (preorder.size() != inorder.size()) {
            root = nullptr;
            return;
        }
        root = buildPreInHelper(preorder, 0, (int)preorder.size()-1, inorder, 0, (int)inorder.size()-1);
    }

    // Build tree from inorder + postorder (simple linear index search)
    void buildFromInPost(const vector<T>& inorder, const vector<T>& postorder) {
        if (inorder.size() != postorder.size()) {
            root = nullptr;
            return;
        }
        root = buildInPostHelper(inorder, 0, (int)inorder.size()-1, postorder, 0, (int)postorder.size()-1);
    }

    // linear search for value in inorder slice
    int indexOf(const vector<T>& arr, int l, int r, const T& val) {
        for (int i = l; i <= r; ++i) if (arr[i] == val) return i;
        return -1;
    }

    // Helper for buildFromPreIn (no maps)
    Node<T>* buildPreInHelper(const vector<T>& pre, int preL, int preR,
                              const vector<T>& in, int inL, int inR) {
        if (preL > preR || inL > inR) return nullptr;
        T rootVal = pre[preL];
        Node<T>* node = new Node<T>(rootVal);
        int idx = indexOf(in, inL, inR, rootVal);
        if (idx == -1) return node;
        int leftSize = idx - inL;
        node->left  = buildPreInHelper(pre, preL+1, preL+leftSize, in, inL, idx-1);
        node->right = buildPreInHelper(pre, preL+leftSize+1, preR, in, idx+1, inR);
        return node;
    }

    // Helper for buildFromInPost (no maps)
    Node<T>* buildInPostHelper(const vector<T>& in, int inL, int inR,
                               const vector<T>& post, int postL, int postR) {
        if (postL > postR || inL > inR) return nullptr;
        T rootVal = post[postR];
        Node<T>* node = new Node<T>(rootVal);
        int idx = indexOf(in, inL, inR, rootVal);
        if (idx == -1) return node;
        int leftSize = idx - inL;
        node->left  = buildInPostHelper(in, inL, idx-1, post, postL, postL+leftSize-1);
        node->right = buildInPostHelper(in, idx+1, inR, post, postL+leftSize, postR-1);
        return node;
    }
*/
};


int main()
{
    BST<int> obj(100);
    obj.insert(150);
    obj.insert(80);
    obj.insert(70);
    obj.insert(90);
    obj.insert(89);
    obj.insert(95);

    obj.inOrder();
/*    obj.preOrder();
    obj.postOrder();

    obj.deleteMethod(2);
    obj.inOrder();

    // Example: build from preorder + inorder
    vector<int> pre = {5,3,2,4,7,6,8};
    vector<int> in  = {2,3,4,5,6,7,8};
    BST<int> tree1;
    tree1.buildFromPreIn(pre, in);
    cout << "tree1 inOrder: "; tree1.inOrder();

    // Example: build from inorder + postorder
    vector<int> post = {2,4,3,6,8,7,5};
    BST<int> tree2;
    tree2.buildFromInPost(in, post);
    cout << "tree2 preOrder: "; tree2.preOrder();
*/
    return 0;
}