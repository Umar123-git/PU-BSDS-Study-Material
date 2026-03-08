#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class Minimax
{
private:
    vector<vector<char>> game_state;
    int max_depth;

public:
    int nodes_expanded;

    Minimax(vector<vector<char>> state, int depth = 9)
    {
        game_state = state;
        max_depth = depth;
        nodes_expanded = 0;
    }

    // Check if the game finished
    bool is_terminal(vector<vector<char>> state)
    {
        // TODO: Check rows, columns, diagonals for a win

        if(state[0][0] != ' ' && state[0][0] == state[0][1] && state[0][1] == state[0][2]) return true;
        if(state[1][0] != ' ' && state[1][0] == state[1][1] && state[1][1] == state[1][2]) return true;
        if(state[2][0] != ' ' && state[2][0] == state[2][1] && state[2][1] == state[2][2]) return true;

        if(state[0][0] != ' ' && state[0][0] == state[1][0] && state[1][0] == state[2][0]) return true;
        if(state[0][1] != ' ' && state[0][1] == state[1][1] && state[1][1] == state[2][1]) return true;
        if(state[0][2] != ' ' && state[0][2] == state[1][2] && state[1][2] == state[2][2]) return true;

        if(state[0][0] != ' ' && state[0][0] == state[1][1] && state[1][1] == state[2][2]) return true;
        if(state[0][2] != ' ' && state[0][2] == state[1][1] && state[1][1] == state[2][0]) return true;

        return false;

    }

    // Utility for terminal states
    int utility(vector<vector<char>> state)
    {
        // TODO
        int x=0,o=0;
        if(state[0][0] != ' ' && state[0][0] == state[0][1] && state[0][1] == state[0][2]){
            if(state[0][0] == 'X') x++;
            else o++;
        }
        if(state[1][0] != ' ' && state[1][0] == state[1][1] && state[1][1] == state[1][2]){
            if(state[1][0] == 'X') x++;
            else o++;
        }
        if(state[2][0] != ' ' && state[2][0] == state[2][1] && state[2][1] == state[2][2]){
            if(state[2][0] == 'X') x++;
            else o++;
        }

        if(state[0][0] != ' ' && state[0][0] == state[1][0] && state[1][0] == state[2][0]){
            if(state[0][0] == 'X') x++;
            else o++;
        }
        if(state[0][1] != ' ' && state[0][1] == state[1][1] && state[1][1] == state[2][1]){
            if(state[0][1] == 'X') x++;
            else o++;
        }
        if(state[0][2] != ' ' && state[0][2] == state[1][2] && state[1][2] == state[2][2]){
            if(state[0][2] == 'X') x++;
            else o++;
        }

        if(state[0][0] != ' ' && state[0][0] == state[1][1] && state[1][1] == state[2][2]){
            if(state[0][0] == 'X') x++;
            else o++;
        }
        if(state[0][2] != ' ' && state[0][2] == state[1][1] && state[1][1] == state[2][0]){
            if(state[0][2] == 'X') x++;
            else o++;
        }
        return x - o;
    }

    // Heuristic evaluation for non-terminal states
    int heuristic(vector<vector<char>> state)
    {
        // {'X','O','X'},
        // {'O','X',' '},
        // {' ',' ','O'}
        // TODO

        int x=0,o=0,s=0;
        int arr[8] = {0};

        int idx = 0;
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                if(state[i][j] == 'X') x++;
                else if(state[i][j] == 'O') o++;
                else s++;
            }

            if(x>0 && o==0) arr[idx] = 1;
            else if(o>0 && x==0) arr[idx] = -1;
            else arr[idx] = 0;
            idx++;
            x=0,o=0,s=0;
        }

        for(int j=0 ; j<3 ; j++){
            for(int i=0 ; i<3 ; i++){
                if(state[i][j] == 'X') x++;
                else if(state[i][j] == 'O') o++;
                else s++;
            }

            if(x>0 && o==0) arr[idx] = 1;
            else if(o>0 && x==0) arr[idx] = -1;
            else arr[idx] = 0;
            idx++;
            x=0,o=0,s=0;
        }

        for(int i=0 ; i<3 ; i++){
            if(state[i][i] == 'X')x++;
            else if(state[i][i] == 'O')o++;
            else s++;

        }
        if(x>0 && o==0) arr[idx] = 1;
        else if(o>0 && x==0) arr[idx] = -1;
        else arr[idx] = 0;
        idx++;
        x=0,o=0,s=0;

        for(int i=0 ; i<3 ; i++){
            if(state[i][2-i] == 'X')x++;
            else if(state[i][2-i] == 'O')o++;
            else s++;

        }
        if(x>0 && o==0) arr[idx] = 1;
        else if(o>0 && x==0) arr[idx] = -1;
        else arr[idx] = 0;
        idx++;
        x=0,o=0,s=0;



        int sum = 0 ;
        for(int i=0 ; i<8 ; i++){
            sum += arr[i];
        }

        return sum;

    }

    // Minimax algorithm
    int minimax(vector<vector<char>> state, int depth, bool maximizing_player)
    {
        // {'X','O','X'},
        // {'O','X',' '},
        // {' ',' ','O'}
        // TODO

        nodes_expanded++;
        if(is_terminal(state)) 
            return utility(state);


        if(depth == max_depth)
            return heuristic(state);

        if(maximizing_player){
            int best = -1000;
            for(int i=0 ; i<3 ; i++){
                for(int j=0 ; j<3 ; j++){
                    if(state[i][j] == ' '){
                        state[i][j] = 'X';
                        best = max(best,minimax(state,depth+1,false));
                        state[i][j] = ' ';
                    }
                }
            }
            return best;
        }
        else{
            int best = 1000;
            for(int i=0 ; i<3 ; i++){
                for(int j=0 ; j<3 ; j++){
                    if(state[i][j] == ' '){
                        state[i][j] = 'O';
                        best = min(best,minimax(state,depth+1,true));
                        state[i][j] = ' ';
                    }
                }
            }
            return best;

        }


    }

    // Find best move
    pair<int,int> best_move(vector<vector<char>> state)
    {
        // TODO
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                if(state[i][j] == ' '){
                    state[i][j] = 'X';
                    int move_val = minimax(state,0,false);
                    state[i][j] = ' ';
                    if(move_val == 1) return {i,j};
                }
            }
        }
        return {0,0};
    }
};


// Function to print board
void print_board(vector<vector<char>> board)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {

            if(board[i][j] == ' ') cout << "_ ";
            else cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<char>> board =
    {
        {'X','O','X'},
        {'O','X',' '},
        {' ',' ','O'}
    };

    cout<<"Initial Board:\n";
    print_board(board);

    int depths[] = {9,4,2};

    for(int d : depths)
    {
        cout<<"\nRunning Minimax with depth = "<<d<<endl;

        Minimax ai(board,d);

        auto start = chrono::high_resolution_clock::now();

        pair<int,int> move = ai.best_move(board);

        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::microseconds>(end-start);

        cout<<"Best Move: ("<<move.first<<","<<move.second<<")"<<endl;
        cout<<"Nodes Expanded: "<<ai.nodes_expanded<<endl;
        cout<<"Time Taken: "<<duration.count()<<" microseconds"<<endl;
    }

    return 0;
}