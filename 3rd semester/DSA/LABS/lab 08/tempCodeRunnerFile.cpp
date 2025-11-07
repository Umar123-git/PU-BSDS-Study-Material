class Tree
{
private:
    int height;
    T *data;
    bool *status;
public:

    Tree(){
        height=1;
        data = new T[1];
        status = new bool[1];
        status[0]=false;
        
    }
    Tree(int h){
        height=h;
        //cout<< pow(2,h)-1;
        data = new T[15];
        status = new bool[static_cast<int>(pow(2, h)-1)];