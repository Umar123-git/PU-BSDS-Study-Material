class AlphaBetaPruning:
    def __init__(self, depth, state, p):
        self.max_depth = depth
        self.game_state = state
        self.player = p
        self.nodes_expanded = 0

    def is_terminal(self, state):
        # check win or draw
        if state[0] != ' ' and state[0] == state[1] == state[2]: return True
        if state[3] != ' ' and state[3] == state[4] == state[5]: return True
        if state[6] != ' ' and state[6] == state[7] == state[8]: return True

        if state[0] != ' ' and state[0] == state[3] == state[6]: return True
        if state[1] != ' ' and state[1] == state[4] == state[7]: return True
        if state[2] != ' ' and state[2] == state[5] == state[8]: return True

        if state[0] != ' ' and state[0] == state[4] == state[8]: return True
        if state[2] != ' ' and state[2] == state[4] == state[6]: return True

        if ' ' not in state:
            return True

        return False

    def heuristic(self, state):
        x = o = s = 0
        arr = [0]*8
        idx = 0

        for i in range(3):
            for j in range(3):
                if state[i*3 + j] == 'X': x += 1
                elif state[i*3 + j] == 'O': o += 1
                else: s += 1

            if x > 0 and o == 0: arr[idx] = 1
            elif o > 0 and x == 0: arr[idx] = -1
            else: arr[idx] = 0
            idx += 1
            x = o = s = 0

        for j in range(3):
            for i in range(3):
                if state[i*3 + j] == 'X': x += 1
                elif state[i*3 + j] == 'O': o += 1
                else: s += 1

            if x > 0 and o == 0: arr[idx] = 1
            elif o > 0 and x == 0: arr[idx] = -1
            else: arr[idx] = 0
            idx += 1
            x = o = s = 0

        for i in range(3):
            if state[i*3 + i] == 'X': x += 1
            elif state[i*3 + i] == 'O': o += 1
            else: s += 1

        if x > 0 and o == 0: arr[idx] = 1
        elif o > 0 and x == 0: arr[idx] = -1
        else: arr[idx] = 0
        idx += 1
        x = o = s = 0

        for i in range(3):
            if state[i*3 + (2-i)] == 'X': x += 1
            elif state[i*3 + (2-i)] == 'O': o += 1
            else: s += 1

        if x > 0 and o == 0: arr[idx] = 1
        elif o > 0 and x == 0: arr[idx] = -1
        else: arr[idx] = 0
        idx += 1
        x = o = s = 0

        return sum(arr)

    def utility(self, state):
        x = o = 0
        lines = [
            [0,1,2],[3,4,5],[6,7,8],
            [0,3,6],[1,4,7],[2,5,8],
            [0,4,8],[2,4,6]
        ]

        for l in lines:
            if state[l[0]] != ' ' and state[l[0]] == state[l[1]] == state[l[2]]:
                if state[l[0]] == 'O': o += 1
                else: x += 1

        return o - x

    def alphabeta(self, state, depth, alpha, beta, maximizing_player):
        self.nodes_expanded += 1
        if self.is_terminal(state):
            return self.utility(state)
        if depth == self.max_depth:
            return self.heuristic(state)

        if maximizing_player:
            best = -1000
            for i in range(9):
                if state[i] == ' ':
                    state[i] = 'O'
                    best = max(best, self.alphabeta(state, depth+1, alpha, beta, False))
                    state[i] = ' '
                    alpha = max(alpha, best)
                    if beta <= alpha:
                        break
            return best
        else:
            best = 1000
            for i in range(9):
                if state[i] == ' ':
                    state[i] = 'X'
                    best = min(best, self.alphabeta(state, depth+1, alpha, beta, True))
                    state[i] = ' '
                    beta = min(beta, best)
                    if beta <= alpha:
                        break
            return best

    def best_move(self, state):
        best_val = -1000
        best_move = -1
        for i in range(9):
            if state[i] == ' ':
                state[i] = 'O'
                move_val = self.alphabeta(state, 0, -1000, 1000, False)
                state[i] = ' '
                if move_val > best_val:
                    best_val = move_val
                    best_move = i
        return best_move


def print_board(board):
    print(board[0], '|', board[1], '|', board[2])
    print('---------')
    print(board[3], '|', board[4], '|', board[5])
    print('---------')
    print(board[6], '|', board[7], '|', board[8])


def check_winner(board, player):
    win_conditions = [
        [0,1,2],[3,4,5],[6,7,8],
        [0,3,6],[1,4,7],[2,5,8],
        [0,4,8],[2,4,6]
    ]
    for wc in win_conditions:
        if board[wc[0]] == board[wc[1]] == board[wc[2]] == player:
            return True
    return False


def main():
    board = [' ']*9
    human_player = 'X'
    ai_player = 'O'
    current_player = human_player
    ai = AlphaBetaPruning(9, board, ai_player)

    while True:
        empty = ' ' in board
        if not empty:
            break

        print_board(board)

        if current_player == human_player:
            move = int(input("Enter your move (0-8): "))
            if board[move] == ' ':
                board[move] = human_player
                if check_winner(board, human_player):
                    print_board(board)
                    print("You win!")
                    return
                current_player = ai_player
            else:
                print("Invalid move")
        else:
            move = ai.best_move(board)
            board[move] = ai_player
            print("AI selects position", move)
            if check_winner(board, ai_player):
                print_board(board)
                print("AI wins!")
                return
            current_player = human_player

    print_board(board)
    print("Game ended in a draw!")


if __name__ == "__main__":
    main()