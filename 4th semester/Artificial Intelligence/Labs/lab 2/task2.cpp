#include <iostream>
#include <vector>
using namespace std;

class AlphaBetaPruning
{
public:
    int max_depth;
    vector<char> game_state;
    char player;
    int nodes_expanded;

    AlphaBetaPruning(int depth, vector<char> state, char p)
    {
        max_depth = depth;
        game_state = state;
        player = p;
        nodes_expanded = 0;
    }

    bool is_terminal(vector<char> state)
    {
        // check win or draw
        // {'X','O','X'},
        // {'O','X',' '},
        // {' ',' ','O'}
        if(state[0] != ' ' && state[0] == state[1] && state[1] == state[2]) return true;
        if(state[3] != ' ' && state[3] == state[4] && state[4] == state[5]) return true;
        if(state[6] != ' ' && state[6] == state[7] && state[7] == state[8]) return true;

        if(state[0] != ' ' && state[0] == state[3] && state[3] == state[6]) return true;
        if(state[1] != ' ' && state[1] == state[4] && state[4] == state[7]) return true;
        if(state[2] != ' ' && state[2] == state[5] && state[5] == state[8]) return true;

        if(state[0] != ' ' && state[0] == state[4] && state[4] == state[8]) return true;
        if(state[2] != ' ' && state[2] == state[4] && state[4] == state[6]) return true;

        bool full = true;
        for(char c : state)
            if(c == ' ') full = false;

        if(full) return true;

        
        return false;
    }

    int heuristic(vector<char> state)
    {
        // evaluate non-terminal board
        // {'X','O','X'},
        // {'O','X',' '},
        // {' ',' ','O'}
        int x=0,o=0,s=0;
        int arr[8] = {0};

        int idx = 0;
        for(int i=0 ; i<3 ; i++){
            for(int j=0 ; j<3 ; j++){
                if(state[i*3 + j] == 'X') x++;
                else if(state[i*3 + j] == 'O') o++;
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
                if(state[i*3 + j] == 'X') x++;
                else if(state[i*3 + j] == 'O') o++;
                else s++;
            }

            if(x>0 && o==0) arr[idx] = 1;
            else if(o>0 && x==0) arr[idx] = -1;
            else arr[idx] = 0;
            idx++;
            x=0,o=0,s=0;
        }

        for(int i=0 ; i<3 ; i++){
            if(state[i*3 + i] == 'X') x++;
            else if(state[i*3 + i] == 'O') o++;
            else s++;

        }
        if(x>0 && o==0) arr[idx] = 1;
        else if(o>0 && x==0) arr[idx] = -1;
        else arr[idx] = 0;
        idx++;
        x=0,o=0,s=0;

        for(int i=0 ; i<3 ; i++){
            if(state[i*3 + (2-i)] == 'X') x++;
            else if(state[i*3 + (2-i)] == 'O') o++;
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

    int utility(vector<char> state)
    {
        // return value for terminal state

        // 0 | 1 | 2
        // ---------
        // 3 | 4 | 5
        // ---------
        // 6 | 7 | 8
        int x=0,o=0;
        if(state[0] != ' ' && state[0] == state[1] && state[1] == state[2]){
            if(state[0] == 'X') x++;
            else o++;
        }
        if(state[3] != ' ' && state[3] == state[4] && state[4] == state[5]){
            if(state[3] == 'X') x++;
            else o++;
        }
        if(state[6] != ' ' && state[6] == state[7] && state[7] == state[8]){
            if(state[6] == 'X') x++;
            else o++;
        }

        if(state[0] != ' ' && state[0] == state[3] && state[3] == state[6]){
            if(state[0] == 'X') x++;
            else o++;
        }
        if(state[1] != ' ' && state[1] == state[4] && state[4] == state[7]){
            if(state[1] == 'X') x++;
            else o++;
        }
        if(state[2] != ' ' && state[2] == state[5] && state[5] == state[8]){
            if(state[2] == 'X') x++;
            else o++;
        }

        if(state[0] != ' ' && state[0] == state[4] && state[4] == state[8]){
            if(state[0] == 'X') x++;
            else o++;
        }
        if(state[2] != ' ' && state[2] == state[4] && state[4] == state[6]){
            if(state[2] == 'X') x++;
            else o++;
        }
        return o - x;
    }

    int alphabeta(vector<char> state, int depth, int alpha, int beta, bool maximizing_player)
    {
        // implement alpha-beta pruning
        nodes_expanded++;
        if(is_terminal(state)) 
            return utility(state);


        if(depth == max_depth)
            return heuristic(state);

        if(maximizing_player){
            int best = -1000;
            for(int i=0 ; i<9 ; i++){
                if(state[i] == ' '){
                    state[i] = 'O';
                    best = max(best,alphabeta(state,depth+1,alpha,beta,false));
                    state[i] = ' ';
                    alpha = max(alpha,best);
                    if(beta <= alpha) break;
                }
                
            }
            return best;
        }
        else{
            int best = 1000;
            for(int i=0 ; i<9 ; i++){
                if(state[i] == ' '){
                    state[i] = 'X';
                    best = min(best,alphabeta(state,depth+1,alpha,beta,true));
                    state[i] = ' ';
                    beta = min(beta,best);
                    if(beta <= alpha) break;
                }
                
            }
            return best;

        }
    }

    int best_move(vector<char> state)
    {
        // return best move index
        int best_val = -1000;
        int best_move = -1;
        for(int i=0 ; i<9 ; i++){
            if(state[i] == ' '){
                state[i] = 'O';
                int move_val = alphabeta(state,0,-1000,1000,false);
                state[i] = ' ';
                if(move_val > best_val){
                    best_val = move_val;
                    best_move = i;
                }
            }
        }
        return best_move;
    }
};

void print_board(vector<char> board)
{
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---------" << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---------" << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

bool check_winner(vector<char> board, char player)
{
    int win_conditions[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for(int i=0;i<8;i++)
    {
        if(board[win_conditions[i][0]] == player &&
           board[win_conditions[i][1]] == player &&
           board[win_conditions[i][2]] == player)
           return true;
    }

    return false;
}

int main()
{
    vector<char> board(9,' ');

    char human_player = 'X';
    char ai_player = 'O';

    char current_player = human_player;

    AlphaBetaPruning ai(9, board, ai_player);

    while(true)
    {
        bool empty = false;
        for(char c : board)
            if(c == ' ') empty = true;

        if(!empty) break;

        print_board(board);

        if(current_player == human_player)
        {
            int move;
            cout << "Enter your move (0-8): ";
            cin >> move;

            if(board[move] == ' ')
            {
                board[move] = human_player;

                if(check_winner(board,human_player))
                {
                    print_board(board);
                    cout << "You win!" << endl;
                    return 0;
                }

                current_player = ai_player;
            }
            else
            {
                cout << "Invalid move" << endl;
            }
        }

        else
        {
            int move = ai.best_move(board);

            board[move] = ai_player;

            cout << "AI selects position " << move << endl;

            if(check_winner(board,ai_player))
            {
                print_board(board);
                cout << "AI wins!" << endl;
                return 0;
            }

            current_player = human_player;
        }
    }

    print_board(board);
    cout << "Game ended in a draw!" << endl;

    return 0;
}