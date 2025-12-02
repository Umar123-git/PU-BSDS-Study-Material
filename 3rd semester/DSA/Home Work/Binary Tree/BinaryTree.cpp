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

        ~Tree() {
            remove(root);
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
        int getHeight() { return height(root); }


        void setroot(T v){
            if(!root) root = new Node<T>(v);
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
            else cout << "Parent node " << p << " not found!" << endl;
        }

        void setrightchild(T p,T v){
            Node<T>* n = search(root,p);
            if(n && !n->right) n->right = new Node<T>(v);
            else cout << "Parent node " << p << " not found!" << endl;
        }

        void remove(Node<T>* curr){
            if(!curr) return;
            remove(curr->left);
            remove(curr->right);
            delete curr;
        }

        void remove(Node<T>* root, T v){
            if(root){
                if (root && root->data == v) {
                    remove(root);
                    this->root = nullptr;
                    return;
                }

                Node<T>* n = searchparent(root,v);
                if(n){
                    if (n->left && n->left->data == v) {
                        remove(n->left);
                        n->left = nullptr;
                    } 
                    else if (n->right && n->right->data == v) {
                        remove(n->right);
                        n->right = nullptr;
                    }

                }
            }
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
};

int main() {
    Tree<int> t;
    t.setroot(1);
    t.setleftchild(1, 2);
    t.setrightchild(1, 3);
    t.setleftchild(2, 4);
    t.setrightchild(2, 5);
    t.setleftchild(3, 6);
    t.setrightchild(3, 7);

    cout << "Preorder: "; t.preOrder(); cout << endl;
    cout << "Inorder: "; t.inOrder(); cout << endl;
    cout << "Postorder: "; t.postOrder(); cout << endl;
    cout << "Levelorder: "; t.levelOrder(); cout << endl;

    t.remove(t.root, 3);
    cout << "\nAfter removing subtree rooted at 3:\n";
    t.levelOrder();
}
