// ...existing code...
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<class T>
class BST{
public:
    Node<T> *root;

    BST(){
        root = nullptr;
    }

    ~BST() {
        deleteTree(root);
    }

    void insert(T node) {
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

    void inOrder()   { inOrderHelper(root); cout << endl; }
    void preOrder()  { preOrderHelper(root); cout << endl; }
    void postOrder() { postOrderHelper(root); cout << endl; }

    void deleteMethod(T node) { root = deleteNode(root, node); }

    bool search(T node) {
        Node<T> *current = root;
        while (current != nullptr) {
            if (current->data == node) return true;
            current = (node < current->data) ? current->left : current->right;
        }
        return false;
    }

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

    void inOrderHelper(Node<T> *p) {
        if (!p) return;
        inOrderHelper(p->left);
        cout << p->data << " ";
        inOrderHelper(p->right);
    }

    void preOrderHelper(Node<T> *p) {
        if (!p) return;
        cout << p->data << " ";
        preOrderHelper(p->left);
        preOrderHelper(p->right);
    }

    void postOrderHelper(Node<T> *p) {
        if (!p) return;
        postOrderHelper(p->left);
        postOrderHelper(p->right);
        cout << p->data << " ";
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
};

// ...existing code...
int main()
{
    BST<int> obj;
    obj.insert(5);
    obj.insert(3);
    obj.insert(7);
    obj.insert(2);
    obj.insert(4);
    obj.insert(6);
    obj.insert(8);

    obj.inOrder();
    obj.preOrder();
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

    return 0;
}
// ...existing code...