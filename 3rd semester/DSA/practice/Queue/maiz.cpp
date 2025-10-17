#include <iostream>
#include<vector>
//#include<queue>
#include "Queue.h"
using namespace std;

struct Pair {
    int x;
    int y;
};

class maize{
    private:
        Queue<Pair> q;
    public:
        void solve_maze(char maze[6][6], Pair s, Pair d, int row, int col) {
            Queue<Pair> q(100);
            bool visited[6][6] = {false};
            Pair parent[6][6];
            q.enqueue(s);
            visited[s.x][s.y] = true;

            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};

            bool found = false;

            while (!q.isEmpty()) {
                Pair current = q.dequeue();
                if (current.x == d.x && current.y == d.y) 
                {
                    found = true;
                    break;
                }

                for (int i = 0; i < 4; i++) 
                {
                    int nx = current.x + dx[i];
                    int ny = current.y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < row && ny < col) {
                        if (!visited[nx][ny] && (maze[nx][ny] == ' ' || maze[nx][ny] == 'T')) {
                            visited[nx][ny] = true;
                            parent[nx][ny] = current;
                            q.enqueue({nx, ny});
                        }
                    }
                }
            }

            if (found) {
                cout << "solved \n";
                Queue<Pair> path(100);
                Pair temp = d;
                while (!(temp.x == s.x && temp.y == s.y)) {
                    path.enqueue(temp);
                    temp = parent[temp.x][temp.y];
                }

                path.enqueue(s);
                int n = path.size();
                Pair* reversePath = new Pair[n];
                for (int i = n - 1; i >= 0; i--)
                {
                    reversePath[i] = path.dequeue();
                }

                for (int i = 0; i < n; i++) 
                {
                    cout << "(" << reversePath[i].x << "," << reversePath[i].y << ") ";
                }

                cout << endl;
                delete[] reversePath;
            } else {
                cout << "unsolved" << endl;
            }
        }
    
};

int main() {
    maize m;
    char maze1[6][6] = {
        {' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', ' '},
        {'P', ' ', ' ', ' ', '*', ' '},
        {'*', ' ', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', '*', 'T'},
        {'*', ' ', ' ', ' ', ' ', ' '}
    };

    Pair start = {2, 0};
    Pair dest = {4, 5};

    m.solve_maze(maze1, start, dest, 6, 6);

    char maze2[6][6] = {
        {' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', ' '},
        {'P', ' ', ' ', ' ', '*', ' '},
        {'*', '*', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', '*', 'T'},
        {'*', ' ', ' ', ' ', ' ', ' '}
    };

    m.solve_maze(maze2, start, dest, 6, 6);

    return 0;
}

