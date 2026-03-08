import time

class Minimax:
    def __init__(self, state, depth=9):
        self.game_state = state
        self.max_depth = depth
        self.nodes_expanded = 0

    # Check if the game finished
    def is_terminal(self, state):
        if state[0][0] != ' ' and state[0][0] == state[0][1] == state[0][2]:
            return True
        if state[1][0] != ' ' and state[1][0] == state[1][1] == state[1][2]:
            return True
        if state[2][0] != ' ' and state[2][0] == state[2][1] == state[2][2]:
            return True

        if state[0][0] != ' ' and state[0][0] == state[1][0] == state[2][0]:
            return True
        if state[0][1] != ' ' and state[0][1] == state[1][1] == state[2][1]:
            return True
        if state[0][2] != ' ' and state[0][2] == state[1][2] == state[2][2]:
            return True

        if state[0][0] != ' ' and state[0][0] == state[1][1] == state[2][2]:
            return True
        if state[0][2] != ' ' and state[0][2] == state[1][1] == state[2][0]:
            return True

        return False

    # Utility for terminal states
    def utility(self, state):
        x = 0
        o = 0

        if state[0][0] != ' ' and state[0][0] == state[0][1] == state[0][2]:
            x += 1 if state[0][0] == 'X' else 0
            o += 1 if state[0][0] == 'O' else 0
        if state[1][0] != ' ' and state[1][0] == state[1][1] == state[1][2]:
            x += 1 if state[1][0] == 'X' else 0
            o += 1 if state[1][0] == 'O' else 0
        if state[2][0] != ' ' and state[2][0] == state[2][1] == state[2][2]:
            x += 1 if state[2][0] == 'X' else 0
            o += 1 if state[2][0] == 'O' else 0

        if state[0][0] != ' ' and state[0][0] == state[1][0] == state[2][0]:
            x += 1 if state[0][0] == 'X' else 0
            o += 1 if state[0][0] == 'O' else 0
        if state[0][1] != ' ' and state[0][1] == state[1][1] == state[2][1]:
            x += 1 if state[0][1] == 'X' else 0
            o += 1 if state[0][1] == 'O' else 0
        if state[0][2] != ' ' and state[0][2] == state[1][2] == state[2][2]:
            x += 1 if state[0][2] == 'X' else 0
            o += 1 if state[0][2] == 'O' else 0

        if state[0][0] != ' ' and state[0][0] == state[1][1] == state[2][2]:
            x += 1 if state[0][0] == 'X' else 0
            o += 1 if state[0][0] == 'O' else 0
        if state[0][2] != ' ' and state[0][2] == state[1][1] == state[2][0]:
            x += 1 if state[0][2] == 'X' else 0
            o += 1 if state[0][2] == 'O' else 0

        return x - o

    # Heuristic evaluation for non-terminal states
    def heuristic(self, state):
        x = 0
        o = 0
        s = 0
        arr = [0]*8
        idx = 0

        for i in range(3):
            for j in range(3):
                if state[i][j] == 'X':
                    x += 1
                elif state[i][j] == 'O':
                    o += 1
                else:
                    s += 1
            if x > 0 and o == 0:
                arr[idx] = 1
            elif o > 0 and x == 0:
                arr[idx] = -1
            else:
                arr[idx] = 0
            idx += 1
            x = o = s = 0

        for j in range(3):
            for i in range(3):
                if state[i][j] == 'X':
                    x += 1
                elif state[i][j] == 'O':
                    o += 1
                else:
                    s += 1
            if x > 0 and o == 0:
                arr[idx] = 1
            elif o > 0 and x == 0:
                arr[idx] = -1
            else:
                arr[idx] = 0
            idx += 1
            x = o = s = 0

        for i in range(3):
            if state[i][i] == 'X':
                x += 1
            elif state[i][i] == 'O':
                o += 1
            else:
                s += 1
        if x > 0 and o == 0:
            arr[idx] = 1
        elif o > 0 and x == 0:
            arr[idx] = -1
        else:
            arr[idx] = 0
        idx += 1
        x = o = s = 0

        for i in range(3):
            if state[i][2-i] == 'X':
                x += 1
            elif state[i][2-i] == 'O':
                o += 1
            else:
                s += 1
        if x > 0 and o == 0:
            arr[idx] = 1
        elif o > 0 and x == 0:
            arr[idx] = -1
        else:
            arr[idx] = 0
        idx += 1
        x = o = s = 0

        return sum(arr)

    # Minimax algorithm
    def minimax(self, state, depth, maximizing_player):
        self.nodes_expanded += 1
        if self.is_terminal(state):
            return self.utility(state)

        if depth == self.max_depth:
            return self.heuristic(state)

        if maximizing_player:
            best = -1000
            for i in range(3):
                for j in range(3):
                    if state[i][j] == ' ':
                        state[i][j] = 'X'
                        best = max(best, self.minimax(state, depth+1, False))
                        state[i][j] = ' '
            return best
        else:
            best = 1000
            for i in range(3):
                for j in range(3):
                    if state[i][j] == ' ':
                        state[i][j] = 'O'
                        best = min(best, self.minimax(state, depth+1, True))
                        state[i][j] = ' '
            return best

    # Find best move
    def best_move(self, state):
        for i in range(3):
            for j in range(3):
                if state[i][j] == ' ':
                    state[i][j] = 'X'
                    move_val = self.minimax(state, 0, False)
                    state[i][j] = ' '
                    if move_val == 1:
                        return (i,j)
        return (0,0)

# Function to print board
def print_board(board):
    for row in board:
        for cell in row:
            if cell == ' ':
                print("_", end=" ")
            else:
                print(cell, end=" ")
        print()

# Main execution
if __name__ == "__main__":
    board = [
        ['X','O','X'],
        ['O','X',' '],
        [' ',' ','O']
    ]

    print("Initial Board:")
    print_board(board)

    depths = [9,4,2]

    for d in depths:
        print(f"\nRunning Minimax with depth = {d}")
        ai = Minimax(board, d)

        start = time.time()
        move = ai.best_move(board)
        end = time.time()

        print(f"Best Move: {move}")
        print(f"Nodes Expanded: {ai.nodes_expanded}")
        print(f"Time Taken: {(end-start)*1e6:.0f} microseconds")