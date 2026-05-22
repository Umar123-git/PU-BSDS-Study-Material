class Puzzle:
    def __init__(self, initial_state, goal_state):
        self.initial_state = initial_state
        self.goal_state = goal_state

    def depth_limited_search(self, state, depth, visited):
        if state == self.goal_state:
            return [state]

        if depth == 0:
            return None

        key = tuple(map(tuple, state))
        if key in visited:
            return None

        visited.add(key)

        for next_state in self.generate_moves(state):
            result = self.depth_limited_search(next_state, depth - 1, visited)
            if result is not None:
                return [state] + result

        visited.remove(key)
        return None

    def iddfs(self):
        if not self.is_solvable(self.initial_state):
            print("Puzzle is not solvable!")
            return None

        depth = 0
        while True:
            print(f"Searching at depth: {depth}")
            visited = set()
            result = self.depth_limited_search(self.initial_state, depth, visited)

            if result is not None:
                return result

            depth += 1
            if depth > 60:
                print("Max depth reached")
                return None

    def generate_moves(self, state):
        n = len(state)
        moves = []

        blank_row, blank_col = -1, -1
        for i in range(n):
            for j in range(n):
                if state[i][j] == 0:
                    blank_row, blank_col = i, j
                    break
            if blank_row != -1:
                break

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        for dr, dc in directions:
            nr = blank_row + dr
            nc = blank_col + dc

            if 0 <= nr < n and 0 <= nc < n:
                new_state = [row[:] for row in state]
                new_state[blank_row][blank_col], new_state[nr][nc] = new_state[nr][nc], new_state[blank_row][blank_col]
                moves.append(new_state)

        return moves

    def is_solvable(self, state):
        n = len(state)
        arr = []
        blank_row_from_bottom = 0

        for i in range(n):
            for j in range(n):
                if state[i][j] == 0:
                    blank_row_from_bottom = n - i
                else:
                    arr.append(state[i][j])

        inversions = 0
        for i in range(len(arr)):
            for j in range(i + 1, len(arr)):
                if arr[i] > arr[j]:
                    inversions += 1

        if n % 2 == 1:
            solvable = inversions % 2 == 0
        else:
            solvable = (inversions + blank_row_from_bottom) % 2 == 1

        print("Inversions:", inversions, "Blank row from bottom:", blank_row_from_bottom, "Solvable:", solvable)
        return solvable


if __name__ == "__main__":
    initial = [
        [1, 2, 3, 4],
        [5, 0, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 6]
    ]
    goal = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 0, 15]
    ]

    puzzle = Puzzle(initial, goal)
    solution = puzzle.iddfs()

    if solution:
        print(f"\nSolution found in {len(solution) - 1} moves:")
        for step, st in enumerate(solution):
            print(f"\nStep {step}:")
            for row in st:
                print(row)
    else:
        print("No solution found.")