import time
import heapq

class PuzzleNode:
    def __init__(self, state, parent, move, g_cost, h_cost):
        self.state = state
        self.parent = parent
        self.move = move
        self.g_cost = g_cost
        self.h_cost = h_cost
        self.f_cost = g_cost + h_cost

    def generate_children(self):
        n = len(self.state)
        children = []

        blank_row, blank_col = -1, -1
        for i in range(n):
            for j in range(n):
                if self.state[i][j] == 0:
                    blank_row, blank_col = i, j
                    break
            if blank_row != -1:
                break

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        moves = ["UP", "DOWN", "LEFT", "RIGHT"]

        for idx, (dr, dc) in enumerate(directions):
            nr = blank_row + dr
            nc = blank_col + dc

            if 0 <= nr < n and 0 <= nc < n:
                new_state = [row[:] for row in self.state]
                new_state[blank_row][blank_col], new_state[nr][nc] = new_state[nr][nc], new_state[blank_row][blank_col]
                child = PuzzleNode(new_state, self, moves[idx], self.g_cost + 1, 0)
                children.append(child)

        return children

    @staticmethod
    def calculate_heuristic(state, goal_state, heuristic_type="manhattan"):
        n = len(state)

        if heuristic_type == "manhattan":
            distance = 0
            for i in range(n):
                for j in range(n):
                    if state[i][j] != 0:
                        for gi in range(n):
                            for gj in range(n):
                                if goal_state[gi][gj] == state[i][j]:
                                    distance += abs(i - gi) + abs(j - gj)
            return distance

        elif heuristic_type == "misplaced_tiles":
            count = 0
            for i in range(n):
                for j in range(n):
                    if state[i][j] != goal_state[i][j]:
                        count += 1
            return count

        elif heuristic_type == "euclidean":
            distance = 0
            for i in range(n):
                for j in range(n):
                    if state[i][j] != 0:
                        for gi in range(n):
                            for gj in range(n):
                                if goal_state[gi][gj] == state[i][j]:
                                    distance += ((i - gi) ** 2 + (j - gj) ** 2) ** 0.5
            return distance

        elif heuristic_type == "linear_conflict":
            distance = PuzzleNode.calculate_heuristic(state, goal_state, "manhattan")
            n = len(state)
            conflict = 0

            for i in range(n):
                for j1 in range(n):
                    for j2 in range(j1 + 1, n):
                        if state[i][j1] != 0 and state[i][j2] != 0:
                            for gi in range(n):
                                if goal_state[gi][j1] == state[i][j2] and goal_state[gi][j2] == state[i][j1]:
                                    conflict += 2

            for j in range(n):
                for i1 in range(n):
                    for i2 in range(i1 + 1, n):
                        if state[i1][j] != 0 and state[i2][j] != 0:
                            for gj in range(n):
                                if goal_state[i1][gj] == state[i2][j] and goal_state[i2][gj] == state[i1][j]:
                                    conflict += 2

            return distance + conflict

        elif heuristic_type == "zero":
            return 0

        return 0

    def __lt__(self, other):
        return self.f_cost < other.f_cost


class PuzzleSolver:
    def __init__(self, start_state, goal_state):
        self.start_state = start_state
        self.goal_state = goal_state

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

        return solvable

    def astar_search(self, heuristic_type="manhattan"):
        start_node = PuzzleNode(self.start_state, None, None, 0, 0)
        start_node.h_cost = PuzzleNode.calculate_heuristic(start_node.state, self.goal_state, heuristic_type)
        start_node.f_cost = start_node.g_cost + start_node.h_cost

        open_list = []
        closed_set = set()

        heapq.heappush(open_list, start_node)

        while open_list:
            current_node = heapq.heappop(open_list)

            if current_node.state == self.goal_state:
                return current_node

            state_tuple = tuple(map(tuple, current_node.state))
            if state_tuple in closed_set:
                continue

            closed_set.add(state_tuple)

            children = current_node.generate_children()
            for child in children:
                child.h_cost = PuzzleNode.calculate_heuristic(child.state, self.goal_state, heuristic_type)
                child.f_cost = child.g_cost + child.h_cost

                child_tuple = tuple(map(tuple, child.state))
                if child_tuple not in closed_set:
                    heapq.heappush(open_list, child)

        return None

    def trace_solution(self, node):
        path = []
        current = node

        while current:
            path.append(current.state)
            current = current.parent

        path.reverse()

        print(f"Steps: {len(path) - 1}")
        for step, state in enumerate(path):
            print(f"\nStep {step}:")
            for row in state:
                print(row)


initial_state = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 0, 15]]
goal_state = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 0]]

solver = PuzzleSolver(initial_state, goal_state)

if solver.is_solvable(initial_state):
    print("The puzzle is solvable. Proceeding with A* Search...\n")

    print("Running A* Search (Manhattan Distance)...")
    start_time = time.time()
    astar_solution_manhattan = solver.astar_search(heuristic_type="manhattan")
    end_time = time.time()

    if astar_solution_manhattan:
        print("\nSolution (Manhattan Distance):")
        solver.trace_solution(astar_solution_manhattan)
        print(f"Execution Time: {end_time - start_time:.5f} seconds\n")

    print("Running A* Search (Misplaced Tiles)...")
    start_time = time.time()
    astar_solution_misplaced = solver.astar_search(heuristic_type="misplaced_tiles")
    end_time = time.time()

    if astar_solution_misplaced:
        print("\nSolution (Misplaced Tiles):")
        solver.trace_solution(astar_solution_misplaced)
        print(f"Execution Time: {end_time - start_time:.5f} seconds\n")

    print("Running A* Search (Euclidean Distance)...")
    start_time = time.time()
    astar_solution_euclidean = solver.astar_search(heuristic_type="euclidean")
    end_time = time.time()

    if astar_solution_euclidean:
        print("\nSolution (Euclidean Distance):")
        solver.trace_solution(astar_solution_euclidean)
        print(f"Execution Time: {end_time - start_time:.5f} seconds\n")

    print("Running A* Search (Linear Conflict)...")
    start_time = time.time()
    astar_solution_linear = solver.astar_search(heuristic_type="linear_conflict")
    end_time = time.time()

    if astar_solution_linear:
        print("\nSolution (Linear Conflict):")
        solver.trace_solution(astar_solution_linear)
        print(f"Execution Time: {end_time - start_time:.5f} seconds\n")

else:
    print("The puzzle is NOT solvable.")