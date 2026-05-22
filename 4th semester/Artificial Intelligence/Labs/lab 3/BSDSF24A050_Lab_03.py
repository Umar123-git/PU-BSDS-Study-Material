import random

# =========================================
# Global Variables
# =========================================
items = [
    (2, 12), (1, 10), (3, 20), (2, 15), (4, 25), (5, 30), (7, 42), (6, 35), (3, 18), (2, 14),
    (8, 50), (9, 55), (4, 24), (5, 28), (1, 8), (6, 33), (7, 40), (3, 16), (2, 11), (4, 22),
    (10, 60), (9, 52), (5, 29), (6, 34), (2, 13), (1, 7), (8, 48), (7, 39), (3, 19), (4, 23)
]

MAX_WEIGHT = 60
best_solution = []
POPULATION_SIZE = 30
MUTATION_RATE = 0.05
GENERATIONS = 50
TOURNAMENT_SIZE = 3

# =========================================
# Initialize Population
# =========================================
def initialize_population(size, num_items):
    population = []
    for i in range(size):
        chromosome = [random.randint(0, 1) for _ in range(num_items)]
        population.append(chromosome)
    return population

# =========================================
# Fitness Function
# =========================================
def fitness(chromosome, items, max_weight):
    total_weight = 0
    total_value = 0
    for i in range(len(chromosome)):
        if chromosome[i] == 1:
            total_weight += items[i][0]
            total_value += items[i][1]
    if total_weight > max_weight:
        return 0
    return total_value

# =========================================
# Roulette Wheel Selection
# =========================================
def roulette_wheel_selection(population, items, max_weight):
    global best_solution
    fitness_values = [fitness(chrom, items, max_weight) for chrom in population]
    total_fitness = sum(fitness_values)

    probabilities = [f / total_fitness for f in fitness_values]

    r = random.random()
    cumulative = 0.0
    for i in range(len(population)):
        cumulative += probabilities[i]
        if r <= cumulative:
            best_solution = population[i]
            break

# =========================================
# Tournament Selection
# =========================================
def tournament_selection(population, items, max_weight, k=3):
    global best_solution
    best_index = 0
    for i in range(len(population)):
        tournament = [random.randint(0, len(population)-1) for _ in range(k)]
        best_index = tournament[0]
        for j in range(1, len(tournament)):
            if fitness(population[tournament[j]], items, max_weight) > fitness(population[best_index], items, max_weight):
                best_index = tournament[j]
    best_solution = population[best_index]

# =========================================
# Selection Dispatcher
# =========================================
def select_parent(population, items, max_weight, method):
    if method == "roulette":
        roulette_wheel_selection(population, items, max_weight)
        return best_solution
    elif method == "tournament":
        tournament_selection(population, items, max_weight, TOURNAMENT_SIZE)
        return best_solution
    return random.choice(population)

# =========================================
# Crossover
# =========================================
def crossover(parent1, parent2):
    point = random.randint(0, len(parent1)-1)
    child1 = []
    child2 = []
    for i in range(len(parent1)):
        if i <= point:
            child1.append(parent1[i])
            child2.append(parent2[i])
        else:
            child1.append(parent2[i])
            child2.append(parent1[i])
    return child1, child2

# =========================================
# Mutation
# =========================================
def mutate(chromosome, mutation_rate):
    for i in range(len(chromosome)):
        if random.random() < mutation_rate:
            chromosome[i] = 1 - chromosome[i]

# =========================================
# Display Solution
# =========================================
def display_solution(solution, items, selection_method):
    total_weight = 0
    total_value = 0

    print("Best Chromosome:", " ".join(map(str, solution)))

    for i in range(len(solution)):
        if solution[i] == 1:
            total_weight += items[i][0]
            total_value += items[i][1]

    fitness_value = fitness(solution, items, MAX_WEIGHT)

    print("Total Fitness:", fitness_value)
    print("Selected Items:", end=" ")
    for i in range(len(solution)):
        if solution[i] == 1:
            print(f"(W:{items[i][0]}, V:{items[i][1]})", end=" ")
    print()
    print("Total Weight:", total_weight)
    print("Total Value:", total_value)
    print("Selection Method Used:", selection_method)

# =========================================
# Genetic Algorithm
# =========================================
def genetic_algorithm(items, max_weight, selection_method):
    global best_solution
    population = initialize_population(POPULATION_SIZE, len(items))
    best_solution = population[0]

    for gen in range(GENERATIONS):
        new_population = []
        while len(new_population) < POPULATION_SIZE:
            parent1 = select_parent(population, items, max_weight, selection_method)
            parent2 = select_parent(population, items, max_weight, selection_method)

            child1, child2 = crossover(parent1, parent2)

            mutate(child1, MUTATION_RATE)
            mutate(child2, MUTATION_RATE)

            new_population.append(child1)
            new_population.append(child2)

        population = new_population

        for chrom in population:
            if fitness(chrom, items, max_weight) > fitness(best_solution, items, max_weight):
                best_solution = chrom

    display_solution(best_solution, items, selection_method)

# =========================================
# Main
# =========================================
if __name__ == "__main__":
    random.seed()
    print("Running Genetic Algorithm with Tournament Selection:")
    genetic_algorithm(items, MAX_WEIGHT, "tournament")

    print("\nRunning Genetic Algorithm with Roulette Wheel Selection:")
    genetic_algorithm(items, MAX_WEIGHT, "roulette")
