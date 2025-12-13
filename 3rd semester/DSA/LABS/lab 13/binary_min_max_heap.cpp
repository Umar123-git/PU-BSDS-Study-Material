#include<iostream>
#include<array>
#include<vector>
#include<cmath>
#include<math.h>
using namespace std;

template<typename T>
class Tree {
private:
    int height;
    T *data;
    bool *status;
public:
    Tree() {
        height = 1;
        data = new T[1];
        status = new bool[1];
        status[0] = false;
    }

    Tree(int h) {
        height = h;
        data = new T[static_cast<int>(pow(2, h)) - 1];
        status = new bool[static_cast<int>(pow(2, h)) - 1];
        for (int i = 0; i < pow(2, h) - 1; i++) {
            status[i] = false;
        }
    }

    ~Tree() {
        delete[] data;
        delete[] status;
        height = 0;
    }

    void setroot(T v) {
        if (status[0] == false) {
            status[0] = true;
            data[0] = v;
        }
    }

    T getroot() {
        if (status[0] == true) {
            return data[0];
        }
        return T(); 
    }

    void setleft(T p, T v) {
        for (int i = 0; i < pow(2, height) - 1; i++) {
            if (data[i] == p && (2 * i) + 1 < pow(2, height) - 1) {
                data[(2 * i) + 1] = v;
                status[(2 * i) + 1] = true;
            }
        }
    }

    void setright(T p, T v) {
        for (int i = 0; i < pow(2, height) - 1; i++) {
            if (data[i] == p && (2 * i) + 2 < pow(2, height) - 1) {
                data[(2 * i) + 2] = v;
                status[(2 * i) + 2] = true;
            }
        }
    }

    T getparent(T p) {
        for (int i = 0; i < pow(2, height) - 1; i++) {
            if (status[i] &&
                (((2 * i) + 1 < pow(2, height) - 1 && status[(2 * i) + 1] && data[(2 * i) + 1] == p) ||
                 ((2 * i) + 2 < pow(2, height) - 1 && status[(2 * i) + 2] && data[(2 * i) + 2] == p))) {
                return data[i];
            }
        }
        throw "\nNo such parent exist";
    }

    void helperremove(int i) {
        if (!status[i] || i >= pow(2, height) - 1) return;
        helperremove(2 * i + 1);
        helperremove(2 * i + 2);
        status[i] = false;
    }

    void remove(T v) {
        for (int i = 0; i < pow(2, height) - 1; i++) {
            if (status[i] && data[i] == v) {
                helperremove(i);
            }
        }
    }

    void helperancestors(int i) {
        if (i <= 0) return;
        cout << data[i];
        helperancestors((i - 1) / 2);
    }

    void ancestors(T v) {
        for (int i = 0; i < pow(2, height) - 1; i++) {
            if (status[i] && data[i] == v) {
                if (i == 0) return;
                helperancestors((i - 1) / 2);
                cout << data[0];
            }
        }
        cout << endl;
    }

    void heldecenders(int i) {
        if (i >= pow(2, height) - 1) return;
        if (status[i]) cout << data[i] << " ";
        heldecenders((i * 2) + 1);
        heldecenders((i * 2) + 2);
    }

    void decenders(T v) {
        for (int i = 0; i < pow(2, height) - 1; i++) {
            if (status[i] && data[i] == v) {
                if ((2 * i) + 1 < pow(2, height) - 1 && status[(2 * i) + 1]) heldecenders((2 * i) + 1);
                if ((2 * i) + 2 < pow(2, height) - 1 && status[(2 * i) + 2]) heldecenders((2 * i) + 2);
            }
        }
        cout << endl;
    }

    int helperdepth(int i, int h) {
        if (i >= pow(2, height) - 1 || !status[i]) return h;
        h++;
        return max(helperdepth((i * 2) + 1, h), helperdepth((i * 2) + 2, h));
    }

    int depth() {
        return helperdepth(0, 0);
    }

    int helperfn(int i, int h){
        if (i <= 0) return h;
        h++;
        return helperfn((i - 1) / 2,h);
    }
    int findLevelOfNode(T node){
        int c=-1;
        for(int i=0 ; i<pow(2,height)-1 ; i++){
            if(status[i] && data[i]==node){
               
                c = helperfn(i,0);
                break;
            }
        }
        return c;
    }

    void displayLevel(int i){
        if(i<0)return;
        if(i==0){
            if(status[0])cout<<data[0];
            return;
        }

        for(int j=pow(2,i-1)-1 ; j<pow(2,i)-1 ; j++){
            if(status[j])cout<<data[j]<<" ";
        }
        cout<<endl;
    }

    void preorder(){
        return heldecenders(0);
    }

    void post(int i){
        if (i >= pow(2, height) - 1) return;
        
        post((i * 2) + 1);
        post((i * 2) + 2);
        if (status[i]) cout << data[i] << " ";
    }
    void postorder(){
        return post(0);
    }

    void in(int i){
        if (i >= pow(2, height) - 1) return;
        
        in((i * 2) + 1);
        if (status[i]) cout << data[i] << " ";
        in((i * 2) + 2);
    }
    void inorder(){
        return in(0);
    }

    void helperdisplayparenthesizedview(int i){
        if (i >= pow(2, height) - 1) return;
        if(status[i])cout<<data[i];
        if((i*2)+1 < pow(2, height) - 1 && status[i]) cout<<" ( ";

        if((2*i)+1 < pow(2, height)-1)helperdisplayparenthesizedview((2*i)+1);
        else if((2*i)+1 >= pow(2, height)-1) return;
        if(status[i])cout<<",";
        
        if((2*i)+2 < pow(2, height)-1)helperdisplayparenthesizedview((2*i)+2);
    
        if(status[i] && i+1< pow(2, height)-1)cout<<" )";
        
    }
    void displayparenthesizedview(){
        return helperdisplayparenthesizedview(0);
    }

    void display() {
        for (int i = 0; i < pow(2, height) - 1; i++) {
            if (status[i]) cout << data[i] << " ";
        }
        cout << endl;
    }


    void max_heapify_down(int A[], int i, int n){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && A[left] > A[largest])
            largest = left;

        if (right < n && A[right] > A[largest])
            largest = right;

        if (largest != i) {
            swap(A[i], A[largest]);
            max_heapify_down(A, largest, n);
        }
    }

    void build_max_heap(int A[]){
        build_tree_from_array(A);
        int n = static_cast<int>(pow(2, height)) - 1;
        for (int i = n / 2 - 1; i >= 0; i--) {
            max_heapify_down(A, i, n);
        }
    }

    void min_heapify_down(int A[], int i, int n){
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && A[left] < A[smallest])
            smallest = left;

        if (right < n && A[right] < A[smallest])
            smallest = right;

        if (smallest != i) {
            swap(A[i], A[smallest]);
            min_heapify_down(A, smallest, n);
        }
    }

    void build_min_heap(int A[]){
        build_tree_from_array(A);
        int n = static_cast<int>(pow(2, height)) - 1;
        for (int i = n / 2 - 1; i >= 0; i--) {
            min_heapify_down(A, i, n);
        }
    }

    void build_tree_from_array(int A[]){
        int n = static_cast<int>(pow(2, height)) - 1;
        for (int i = 0; i < n; i++) {
            data[i] = A[i];
            status[i] = true;
        }
    }

    void display_heap(int A[]){
        int n = static_cast<int>(pow(2, height)) - 1;
        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }


};

int main() {
    cout << "----------------Task 1----------------\n";
    Tree<int> t(4);

    cout << "----------------Task 2 and 3----------------\n";
    t.setroot(10);
    //cout << t.getroot();

    int arr[] = {10, 15, 30, 40, 50, 100, 25, 45, 60, 70, 80, 90, 110, 120, 130};
    t.build_max_heap(arr);
    t.display();
    t.build_min_heap(arr);
    t.display();

    //cout << "\n----------------Task 4 and 5----------------\n";
    //t.setleft ('A', 'B');
    //t.setright('A', 'C');
    //t.setleft ('B', 'D');
    //t.setright('B', 'E');
    //t.setleft ('C', 'F');
    //t.setright('C', 'G');
    //t.setleft ('D', 'H');
    //t.setright('D', 'I');
    //t.setleft ('E', 'J');
    //t.setright('E', 'K');
    //t.setleft ('F', 'L');
    //t.setright('F', 'M');
    //t.setleft ('G', 'N');
    //t.setright('G', 'O');
//
    //t.display();
    //cout << "----------------Task 6----------------\n";
    //cout << t.getparent('O') << endl;
//
    //cout << "----------------Task 7----------------\n";
    //t.remove('B');
    //t.display();
//
    //cout << "----------------Task 8----------------\n";
    //t.ancestors('O');
//
    //cout << "----------------Task 9----------------\n";
    //t.decenders('A');
//
    //cout << "----------------Task 10----------------\n";
    //cout << t.depth() << endl;
//
    //cout << "----------------Task 11----------------\n";
    //t.preorder();
    //cout<<endl;
//
    //cout << "----------------Task 12----------------\n";
    //t.postorder();
    //cout<<endl;
//
    //cout << "----------------Task 13----------------\n";
    //t.inorder();
    //cout<<endl;
//
    //cout << "----------------Task 14----------------\n";
    //t.display();
//
    //cout << "----------------Task 15----------------\n";
    //t.displayLevel(1);
//
    //cout << "----------------Task 16----------------\n";
    //cout<<t.findLevelOfNode('A');
    //cout<<endl;
//
    //cout << "----------------Task 17----------------\n";
    //t.displayparenthesizedview();


    return 0;
}
