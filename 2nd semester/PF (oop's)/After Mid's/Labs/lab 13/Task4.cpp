#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Toss function to decide Player 1 and Player 2


class Player {
    char mark; // O or X
public:
    Player(char m) { mark = m; }
    virtual int getMove() = 0;
    char getMark() const { return mark; }
};

void toss(Player*& p1, Player*& p2) {
    cout << "Tossing a coin to decide Player 1 and Player 2...\n";
    int tossResult = rand() % 2; // Randomly generate 0 or 1
    if (tossResult == 0) {
        cout << "Player 1 remains as is.\n";
    } else {
        cout << "Swapping Player 1 and Player 2.\n";
        swap(p1, p2); // Swap Player 1 and Player 2
    }
}
class HPlayer : public Player {
public:
    HPlayer(char mark) : Player(mark) {}
    int getMove() {
        int index;
        cout << "Enter box number to put " << getMark() << " : ";
        cin >> index;
        return index;
    }
};

class Nonsense : public Player {
public:
    Nonsense(char mark) : Player(mark) {}
    int getMove() {
        int index;
        cout << "Computer's turn " << getMark() << " : ";
        index = rand() % 9 + 1;
        return index;
    }
};

class Board {
    char arr[9];
    bool setMove(int index, char mark) {
        char m = arr[index - 1];
        cout << "Index:" << index << '\t' << "Mark:" << m << '\t';
        if (m >= '1' && m <= '9') {
            arr[index - 1] = mark;
            cout << arr[index - 1] << '\n';
            return true;
        }
        return false;
    }
    friend class Game;

public:
    void init() {
        for (int i = 0; i < 9; i++)
            arr[i] = i + 49;
    }
    void getBoard(char b[]) {
        for (int i = 0; i < 9; i++)
            b[i] = arr[i];
    }
    void draw() {
        cout << endl;
        cout << " ___ ___ ___ " << endl;
        cout << "|   |   |   |" << endl;
        cout << "| " << arr[0] << " | " << arr[1] << " | " << arr[2] << " |" << endl;
        cout << "|___|___|___|" << endl;
        cout << "|   |   |   |" << endl;
        cout << "| " << arr[3] << " | " << arr[4] << " | " << arr[5] << " |" << endl;
        cout << "|___|___|___|" << endl;
        cout << "|   |   |   |" << endl;
        cout << "| " << arr[6] << " | " << arr[7] << " | " << arr[8] << " |" << endl;
        cout << "|___|___|___|" << endl;
    }
};

class Sensible : public Player {
    Board* board;
public:
    Sensible(char mark, Board* b) : Player(mark), board(b) {}

    int getMove() {
        char b[9];
        board->getBoard(b); 
        char opponentMark = (getMark() == 'O') ? 'X' : 'O';

        for (int i = 0; i < 3; i++) {
          
            if (b[i * 3] == getMark() && b[i * 3 + 1] == getMark() && b[i * 3 + 2] >= '1' && b[i * 3 + 2] <= '9')
                return i * 3 + 3;
            if (b[i * 3] == getMark() && b[i * 3 + 2] == getMark() && b[i * 3 + 1] >= '1' && b[i * 3 + 1] <= '9')
                return i * 3 + 2;
            if (b[i * 3 + 1] == getMark() && b[i * 3 + 2] == getMark() && b[i * 3] >= '1' && b[i * 3] <= '9')
                return i * 3 + 1;

            
            if (b[i] == getMark() && b[i + 3] == getMark() && b[i + 6] >= '1' && b[i + 6] <= '9')
                return i + 7;
            if (b[i] == getMark() && b[i + 6] == getMark() && b[i + 3] >= '1' && b[i + 3] <= '9')
                return i + 4;
            if (b[i + 3] == getMark() && b[i + 6] == getMark() && b[i] >= '1' && b[i] <= '9')
                return i + 1;
        }

      
        if (b[0] == getMark() && b[4] == getMark() && b[8] >= '1' && b[8] <= '9')
            return 9;
        if (b[0] == getMark() && b[8] == getMark() && b[4] >= '1' && b[4] <= '9')
            return 5;
        if (b[4] == getMark() && b[8] == getMark() && b[0] >= '1' && b[0] <= '9')
            return 1;

        if (b[2] == getMark() && b[4] == getMark() && b[6] >= '1' && b[6] <= '9')
            return 7;
        if (b[2] == getMark() && b[6] == getMark() && b[4] >= '1' && b[4] <= '9')
            return 5;
        if (b[4] == getMark() && b[6] == getMark() && b[2] >= '1' && b[2] <= '9')
            return 3;

        // Rule 2: Check if there are 2 marks of the opponent in any row, column, or diagonal and the 3rd is free
        for (int i = 0; i < 3; i++) {
            // Check rows
            if (b[i * 3] == opponentMark && b[i * 3 + 1] == opponentMark && b[i * 3 + 2] >= '1' && b[i * 3 + 2] <= '9')
                return i * 3 + 3;
            if (b[i * 3] == opponentMark && b[i * 3 + 2] == opponentMark && b[i * 3 + 1] >= '1' && b[i * 3 + 1] <= '9')
                return i * 3 + 2;
            if (b[i * 3 + 1] == opponentMark && b[i * 3 + 2] == opponentMark && b[i * 3] >= '1' && b[i * 3] <= '9')
                return i * 3 + 1;

            // Check columns
            if (b[i] == opponentMark && b[i + 3] == opponentMark && b[i + 6] >= '1' && b[i + 6] <= '9')
                return i + 7;
            if (b[i] == opponentMark && b[i + 6] == opponentMark && b[i + 3] >= '1' && b[i + 3] <= '9')
                return i + 4;
            if (b[i + 3] == opponentMark && b[i + 6] == opponentMark && b[i] >= '1' && b[i] <= '9')
                return i + 1;
        }

        // Rule 3: Check if there is 1 mark in any row, column, or diagonal and 2nd, 3rd are free
        for (int i = 0; i < 9; i++) {
            if (b[i] >= '1' && b[i] <= '9') // Check for an empty cell
                return i + 1;
        }

        // Rule 4: Select any empty cell
        for (int i = 0; i < 9; i++) {
            if (b[i] >= '1' && b[i] <= '9') // Check for an empty cell
                return i + 1;
        }

        return -1; // Should never reach here
    }
};

class Game {
    Board b;
    Player *p1, *p2;

public:
    Game() {
        init();
        p1 = new HPlayer('O');
        p2 = new HPlayer('X');
        b.draw();
    }
    ~Game() {
    delete p1;
    delete p2;
}

    void init() {
        b.init();
    }
    void runGame() {
        int count = 0, pos, turn = 1, opt;
        char a[9], mark = p1->getMark();
        Player* currentPlayer = p1;

        cout << "Press 1 to select Human vs Human, 2 for Human vs Nonsense Computer, ";
        cout << "3 for Human vs Sensible Computer, 4 for Nonsense vs Sensible Computer: ";
        cin >> opt;

        if (opt < 1 || opt > 4) {
            cout << "Invalid entry";
            return;
        }

        // Allow players to select marks
        cout << "Enter mark for Player 1 (O/X): ";
        char mark1, mark2;
        cin >> mark1;
        mark2 = (mark1 == 'O') ? 'X' : 'O';

        delete p1;
        delete p2;

        if (opt == 1) {
            p1 = new HPlayer(mark1);
            p2 = new HPlayer(mark2);
        } else if (opt == 2) {
            p1 = new HPlayer(mark1);
            p2 = new Nonsense(mark2);
        } else if (opt == 3) {
            p1 = new HPlayer(mark1);
            p2 = new Sensible(mark2, &b);
        } else if (opt == 4) {
            p1 = new Nonsense(mark1);
            p2 = new Sensible(mark2, &b);
        }

        toss(p1, p2); // Call toss to decide Player 1 and Player 2

        while (count < 9) {
            do {
                pos = currentPlayer->getMove();
                mark = currentPlayer->getMark();
            } while (!b.setMove(pos, mark));

            if (turn == 1) {
                turn = 2;
                currentPlayer = p2;
            } else {
                turn = 1;
                currentPlayer = p1;
            }

            b.draw();
            b.getBoard(a);

            if (checkWin(a, pos - 1, mark)) break;
            count++;
        }

        if (count == 9)
            cout << "Draw\n";
        else if (mark == p1->getMark())
            cout << "Player 1 Won\n";
        else
            cout << "Player 2 Won\n";

        // Option to play again
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y') {
            init();
            runGame();
        }
    }

    bool checkRow(char b[], int r, char mark) {
        for (int i = r; i < r + 3; i++)
            if (b[i] != mark) return false;
        return true;
    }
    bool checkColumn(char b[], int r, char mark) {
        for (int i = r; i < 9; i += 3)
            if (b[i] != mark) return false;
        return true;
    }
    bool checkD1(char b[], char mark) {
        return (b[0] == mark && b[4] == mark && b[8] == mark);
    }
    bool checkD2(char b[], char mark) {
        return (b[2] == mark && b[4] == mark && b[6] == mark);
    }
    bool checkWin(char b[], int pos, char mark) {
        if (checkRow(b, pos / 3 * 3, mark)) return true;
        int index;
        if (pos == 0 || pos == 3 || pos == 6) index = 0;
        else if (pos == 1 || pos == 4 || pos == 7) index = 1;
        else index = 2;
        if (checkColumn(b, index, mark)) return true;
        if ((pos == 0 || pos == 4 || pos == 8) && checkD1(b, mark)) return true;
        return checkD2(b, mark);
    }
};

int main() {
    srand(time(0)); // Seed for random number generation
    Game g;
    g.runGame();
    return 0;
}