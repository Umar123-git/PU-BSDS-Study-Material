#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<pair<int, int>> items = {
    {2, 12}, {1, 10}, {3, 20}, {2, 15}, {4, 25}, {5, 30}, {7, 42}, {6, 35}, {3, 18}, {2, 14},
    {8, 50}, {9, 55}, {4, 24}, {5, 28}, {1, 8}, {6, 33}, {7, 40}, {3, 16}, {2, 11}, {4, 22},
    {10, 60}, {9, 52}, {5, 29}, {6, 34}, {2, 13}, {1, 7}, {8, 48}, {7, 39}, {3, 19}, {4, 23}
};

int MAX_WEIGHT = 60;
vector<int> best_solution;
const int POPULATION_SIZE = 30;
const double MUTATION_RATE = 0.05;
const int GENERATIONS = 50;
const int TOURNAMENT_SIZE = 3;

// =========================================
// Initialize Population
// =========================================
vector<vector<int>> initialize_population(int size, int num_items) {
    vector<vector<int>> population(size, vector<int>(num_items));
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < num_items; j++) {
            population[i][j] = rand() % 2;
        }
    }
    return population;
}

// =========================================
// Fitness Function
// =========================================
int fitness(vector<int> chromosome, vector<pair<int,int>> items, int max_weight) {
    int total_weight = 0;
    int total_value = 0;
    for(int i = 0; i < chromosome.size(); i++) {
        if(chromosome[i] == 1) {
            total_weight += items[i].first;
            total_value += items[i].second;
        }
    }
    if(total_weight > max_weight) {
        return 0;
    }
    return total_value; 
}

// =========================================
// Roulette Wheel Selection
// =========================================
void roulette_wheel_selection(vector<vector<int>> population, vector<pair<int,int>> items, int max_weight) {
    vector<double> fitness_values(population.size());
    double total_fitness = 0.0;
    for(int i = 0; i < population.size(); i++) {
        fitness_values[i] = fitness(population[i], items, max_weight);
        total_fitness += fitness_values[i];
    }

    vector<double> probabilities(population.size());
    for(int i = 0; i < population.size(); i++) {
        probabilities[i] = fitness_values[i] / total_fitness;
    }

    double r = (rand() % 100) / 100.0;

    double cumulative = 0.0;
    for(int i = 0; i < population.size(); i++) {
        cumulative += probabilities[i];
        if(r <= cumulative) {
            best_solution = population[i];
            break;
        }
    }
}

// =========================================
// Tournament Selection
// =========================================
void tournament_selection(vector<vector<int>> population, vector<pair<int,int>> items, int max_weight, int k=3) {
    int best_index = 0;
    for(int i = 0; i < population.size(); i++) {
        vector<int> tournament;
        for(int j = 0; j < k; j++) {
            int random_index = rand() % population.size();
            tournament.push_back(random_index);
        }

        best_index = tournament[0];
        for(int j = 1; j < tournament.size(); j++) {
            if(fitness(population[tournament[j]], items, max_weight) > fitness(population[best_index], items, max_weight)) {
                best_index = tournament[j];
            }
        }
    }
    best_solution = population[best_index];
}

// =========================================
// Selection Dispatcher
// =========================================
vector<int> select_parent(vector<vector<int>> population, vector<pair<int,int>> items, int max_weight, string method) {
    if (method == "roulette") {
        roulette_wheel_selection(population, items, max_weight);
        return best_solution;
    } else if (method == "tournament") {
        tournament_selection(population, items, max_weight, TOURNAMENT_SIZE);
        return best_solution;
    }
    return population[rand() % population.size()];
}

// =========================================
// Crossover
// =========================================
pair<vector<int>, vector<int>> crossover(vector<int> parent1, vector<int> parent2) {
    int point = rand() % parent1.size();
    vector<int> child1(parent1.size());
    vector<int> child2(parent2.size());

    for(int i = 0; i < parent1.size(); i++) {
        if(i <= point) {
            child1[i] = parent1[i];
            child2[i] = parent2[i];
        } else {
            child1[i] = parent2[i];
            child2[i] = parent1[i];
        }
    }

    return {child1, child2};
}

// =========================================
// Mutation
// =========================================
void mutate(vector<int>& chromosome, double mutation_rate) {
    for(int i = 0; i < chromosome.size(); i++) {
        if((rand() % 100) / 100.0 < mutation_rate) {
            chromosome[i] = 1 - chromosome[i];
        }
    }
}

// =========================================
// Display Solution
// =========================================
void display_solution(vector<int> solution, vector<pair<int,int>> items, string selection_method) {
    int total_weight = 0;
    int total_value = 0;

    cout << "Best Chromosome: ";
    for (int gene : solution) {
        cout << gene << " ";
    }
    cout << endl;

    for (int i = 0; i < solution.size(); i++) {
        if (solution[i] == 1) {
            total_weight += items[i].first;
            total_value  += items[i].second;
        }
    }

    int fitness_value = fitness(solution, items, MAX_WEIGHT);

    cout << "Total Fitness: " << fitness_value << endl;

    cout << "Selected Items: ";
    for (int i = 0; i < solution.size(); i++) {
        if (solution[i] == 1) {
            cout << "(W:" << items[i].first << ", V:" << items[i].second << ") ";
        }
    }
    cout << endl;

    cout << "Total Weight: " << total_weight << endl;
    cout << "Total Value: " << total_value << endl;
    cout << "Selection Method Used: " << selection_method << endl;
}

// =========================================
// Genetic Algorithm
// =========================================
void genetic_algorithm(vector<pair<int,int>> items, int max_weight, string selection_method) {
    vector<vector<int>> population = initialize_population(POPULATION_SIZE, items.size());

    best_solution = population[0];

    for (int i = 0; i < GENERATIONS; i++) {
        vector<vector<int>> new_population;

        while (new_population.size() < POPULATION_SIZE) {
            vector<int> parent1 = select_parent(population, items, max_weight, selection_method);
            vector<int> parent2 = select_parent(population, items, max_weight, selection_method);

            pair<vector<int>, vector<int>> children = crossover(parent1, parent2);

            mutate(children.first, MUTATION_RATE);
            mutate(children.second, MUTATION_RATE);

            new_population.push_back(children.first);
            new_population.push_back(children.second);
        }

        population = new_population;

        for(auto& chrom : population) {
            if(fitness(chrom, items, max_weight) > fitness(best_solution, items, max_weight)) {
                best_solution = chrom;
            }
        }
    }

    display_solution(best_solution, items, selection_method);
}

// =========================================
// Main
// =========================================
int main() {
    srand(time(0));

    cout << "Running Genetic Algorithm with Tournament Selection:\n";
    genetic_algorithm(items, MAX_WEIGHT, "tournament");

    cout << "\nRunning Genetic Algorithm with Roulette Wheel Selection:\n";
    genetic_algorithm(items, MAX_WEIGHT, "roulette");

    return 0;
}
