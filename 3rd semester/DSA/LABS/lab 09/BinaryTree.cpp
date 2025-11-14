// ...existing code...
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class Node{
    public:
        T data;
        Node<T>* left;
        Node<T>* right;
        Node(){
            left=0;
            right=0;
        }
        Node(T v){
            data=v;
            left=NULL;
            right=NULL;
        }
};

template<typename T>
class Tree{
    public:
        Node<T>* root;

        Tree(){
            root=NULL;
        }

        // copy constructor
        Tree(const Tree<T>& other) {
            root = copyNodes(other.root);
        }

        ~Tree() {
            removehelper(root);
            root = nullptr;
        }


        int count(Node<T>* curr) {
            if (!curr) return 0;
            return 1 + count(curr->left) + count(curr->right);
        }
        int countNodes() { return count(root); }

        int height(Node<T>* curr) {
            if (!curr) return 0;
            return 1 + max(height(curr->left), height(curr->right));
        }
        void getHeight() { cout<< height(root); }


        void setroot(T v){
            if(!root) root = new Node<T>(v);
        }

        T getroot(){
            if(root) return root->data;
            return T();
        }

        Node<T>* search(Node<T>* curr , T p){
            if(!curr)return curr;
            if(curr->data == p)return curr;

            Node<T>* t;
            t=search(curr->left,p);
            if(!t) t = search(curr->right,p);

            return t;
        }

        Node<T>* searchparent(Node<T>* curr, T p){
            if(!curr)return curr;
            if ((curr->left && curr->left->data == p) || (curr->right && curr->right->data == p)) return curr;

            Node<T>* t;
            t=searchparent(curr->left,p);
            if(!t) t = searchparent(curr->right,p);

            return t;
        }

        void setleftchild(T p,T v){
            Node<T>* n = search(root,p);
            if(n && !n->left) n->left = new Node<T>(v);
            else if(!n) cout << "Parent node " << p << " not found!" << endl;
            else cout << "Left child of parent node " << p << " already exists!" << endl;
        }

        void setrightchild(T p,T v){
            Node<T>* n = search(root,p);
            if(n && !n->right) n->right = new Node<T>(v);
            else if(!n) cout << "Parent node " << p << " not found!" << endl;
            else cout << "Right child of parent node " << p << " already exists!" << endl;
        }

        void removehelper(Node<T>* curr){
            if(!curr) return;
            removehelper(curr->left);
            removehelper(curr->right);
            delete curr;
        }

        void removehelper(Node<T>* root, T v){
            if(root){
                if (root && root->data == v) {
                    // remove entire tree rooted at root
                    removehelper(root);
                    // if root was the tree's root, set this->root to nullptr
                    if (root == this->root) this->root = nullptr;
                    return;
                }

                Node<T>* n = searchparent(root,v);
                if(n){
                    if (n->left && n->left->data == v) {
                        removehelper(n->left);
                        n->left = nullptr;
                    } 
                    else if (n->right && n->right->data == v) {
                        removehelper(n->right);
                        n->right = nullptr;
                    }

                }
            }
        }

        
        void remove(T n){
            if(!root) return;
            removehelper(root, n);
        }

        //PREORDER TRAVERSAL
        void preOrder(){
            pre(root);
        }
        void pre(Node<T>* root){
            if(root == NULL){
                return ;
            }
            cout<<root->data<<" ";
            pre(root->left);
            pre(root->right);
        }

        //INORDER TRAVERSAL
        void inOrder(){
            in(root);
        }
        void in(Node<T>* root){
            if(root == NULL){
                return ;
            }
            in(root->left);
            cout<<root->data<<" ";
            in(root->right);
        }

        // POSTORDER TRAVERSAL
        void postOrder(){
            post(root);
        }
        void post(Node<T>* root){
            if(root == NULL){
                return ;
            }
            post(root->left);
            post(root->right);
            cout<<root->data<<" ";
        }

        // LEVELORDER TRAVERSAL
        void levelOrder(){
            if (!root) return;
            queue<Node<T>*> q;
            q.push(root);

            while(!q.empty()){
                Node<T>* curr = q.front();
                q.pop();
                cout<<curr->data<<" ";
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        int sumAtLevel(Node<T>* node, int k, int curr) {
            if (!node) return 0;
            if (curr == k) return node->data;
            return sumAtLevel(node->left, k, curr + 1) + sumAtLevel(node->right, k, curr + 1);
        }

        int sumAtLevelK(int k) {
            return sumAtLevel(root, k, 0);
        }

        // helper that returns parent node pointer (safe)
        Node<T>* getparentNode(Node<T>* r, T n){
            if(!r) return nullptr;
            if ((r->left && r->left->data == n) || (r->right && r->right->data == n)) return r;
            Node<T>* t = getparentNode(r->left, n);
            if(t) return t;
            return getparentNode(r->right, n);
        }

        T getparent(Node<T>* r, T n){
            Node<T>* p = getparentNode(r, n);
            if(p) return p->data;
            return T();
        }
        T getparent(T n){
            if(!root) return T();
            if(n==root->data) return T();
            return getparent(root, n);
        }

        bool isinternalNode(Node<T>* r , T n){
            if(!r)return 0;
            if((r->data == n) && (r->left || r->right))return 1;
            if((r->data == n) && (!r->left && !r->right))return 0;

            return isinternalNode(r->left,n) || isinternalNode(r->right,n);
            
        }
        int isinternalNode(T n){
            return isinternalNode(root, n);
        }

        bool isexternalNode(Node<T>* r , T n){
            if(!r)return 0;
            if((r->data == n) && (r->left || r->right))return 0;
            if((r->data == n) && (!r->left && !r->right))return 1;

            return isexternalNode(r->left,n) || isexternalNode(r->right,n);
            
        }
        int isexternalNode(T n){
            return isexternalNode(root, n);
        }

        Node<T>* getparentfors(Node<T>* r, T n){
            if(!r) return NULL;
            if ((r->left && r->left->data == n) || (r->right && r->right->data == n)) return r;
            Node<T>* t = getparentfors(r->left, n);
            if(t) return t;
            return getparentfors(r->right, n);
        }
        T findsibling(T n){
            Node<T>* r = getparentfors(root, n);
            if(r && r->left && r->left->data!=n) return r->left->data;
            if(r && r->right && r->right->data!=n) return r->right->data;

            return T();
        }

        bool helperdecent(Node<T>* r, T n){
            if(!r) return false;
            if(r->data == n){
                pre(r->left);
                pre(r->right);
                return true;
            }
            if(helperdecent(r->left, n)) return true;
            return helperdecent(r->right, n);
        }
        void displaydecendent(T n){
            helperdecent(root, n);
        }

        // deep-copy helper
        Node<T>* copyNodes(Node<T>* src) {
            if(!src) return nullptr;
            Node<T>* node = new Node<T>(src->data);
            node->left = copyNodes(src->left);
            node->right = copyNodes(src->right);
            return node;
        }

        // assignment operator (deep copy)
        Tree<T>& operator=(const Tree<T>& other){
            if(this == &other) return *this;
            removehelper(root);
            root = copyNodes(other.root);
            return *this;
        }

        void parenthesize(Node<T>* r){
            if(!r) return;
            cout<<r->data;
            if(r->left || r->right){
                cout<<"(";
                if(r->left) parenthesize(r->left);
                cout<<")";
                cout<<"(";
                if(r->right) parenthesize(r->right);
                cout<<")";
            }
        }
        void parenthesize(){
            parenthesize(root);
        }

        Node<T>* mirrorHelper(Node<T>* src) {
            if(!src) return nullptr;
            Node<T>* node = new Node<T>(src->data);
            node->left = mirrorHelper(src->right);
            node->right = mirrorHelper(src->left);
            return node;
        }

        Node<T>* getmirror(){
            return mirrorHelper(root);
        } 

        

};


int main() {
    cout<<"\n----------------Task 1------------------";
    Tree<int> t;
    cout<<"\n----------------Task 2------------------";
    t.setroot(1);
    cout<<"\n----------------Task 3------------------";
    t.getroot();

    cout<<"\n----------------Task 4 and 5------------------";
    t.setleftchild(1, 2);
    t.setrightchild(1, 3);
    t.setleftchild(2, 4);
    t.setrightchild(2, 5);
    t.setleftchild(3, 6);
    t.setrightchild(3, 7);

    cout<<"\n----------------Task 6------------------";
    t.getparent(3);

    cout<<"\n----------------Task 7------------------";
    t.remove(3);
    cout << "\nAfter removing subtree rooted at 3:\n";
    t.levelOrder();

    cout<<"\n----------------Task 8------------------\n";
    cout<<t.isinternalNode(1);

    cout<<"\n----------------Task 9------------------\n";
    cout<<t.isexternalNode(6);

    cout<<"\n----------------Task 10-----------------\n";
    cout<<t.findsibling(4);

    cout<<"\n----------------Task 11------------------";
    cout << "\nPreorder: "; t.preOrder();
    cout<<"\n----------------Task 12------------------";
    cout << "\nPostorder: "; t.postOrder();
    cout<<"\n----------------Task 13------------------";
    cout << "\nInorder: "; t.inOrder();
    cout<<"\n----------------Task 14------------------";
    cout << "\nLevelorder: "; t.levelOrder();

    cout<<"\n----------------Task 15------------------\n";
    t.displaydecendent(3);

    cout<<"\n----------------Task 16------------------\n";
    t.getHeight();

    cout<<"\n----------------Task 17------------------\n";
    cout << "\nParenthesized: "; t.parenthesize();
    cout<<"\n----------------Task 18------------------\n";
     t.~Tree();
    cout<<"\n----------------Task 19------------------\n";
    Tree<int> t2 = t;

    cout<<"\n----------------Task 20------------------\n";
    //t2.copyNodes(t.getroot());

    cout<<"\n----------------Task 21------------------\n";
    cout << "\nMirror preorder: ";
    Node<int>* m = t.getmirror();
    t.pre(m);
    // print mirror preorder
   

    //cout<< "sum of nodes at K : "<<t.sumAtLevelK(2)<<endl;

    
    
}