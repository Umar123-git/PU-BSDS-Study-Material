#include <bits/stdc++.h>
using namespace std;

struct City {
    double x, y;
};


double distance(const City &c1, const City &c2) {
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}


double total_distance(const vector<int> &route, const vector<City> &cities) {
    double dist = 0.0;
    for (int i = 0; i < route.size() - 1; i++) {
        dist += distance(cities[route[i]], cities[route[i+1]]);
    }
    dist += distance(cities[route.back()], cities[route.front()]); // return to start
    return dist;
}


double fitness(const vector<int> &route, const vector<City> &cities) {
    return 1.0 / total_distance(route, cities); // shorter route → higher fitness
}


vector<vector<int>> initialize_population(int size, int num_cities) {
    vector<vector<int>> population;
    for (int i = 0; i < size; i++) {
        vector<int> route(num_cities);
        iota(route.begin(), route.end(), 0);
        random_shuffle(route.begin(), route.end());
        population.push_back(route);
    }
    return population;
}


vector<int> roulette_wheel_selection(const vector<vector<int>> &population, const vector<City> &cities) {
    vector<double> fitnesses;
    double sum = 0.0;
    for (auto &route : population) {
        double f = fitness(route, cities);
        fitnesses.push_back(f);
        sum += f;
    }
    double r = ((double) rand() / RAND_MAX) * sum;
    double cumulative = 0.0;
    for (int i = 0; i < population.size(); i++) {
        cumulative += fitnesses[i];
        if (cumulative >= r) return population[i];
    }
    return population.back();
}


vector<int> tournament_selection(const vector<vector<int>> &population, const vector<City> &cities, int k=3) {
    vector<int> best;
    double best_fit = -1.0;
    for (int i = 0; i < k; i++) {
        int idx = rand() % population.size();
        double f = fitness(population[idx], cities);
        if (f > best_fit) {
            best_fit = f;
            best = population[idx];
        }
    }
    return best;
}


vector<int> select_parent(const vector<vector<int>> &population, const vector<City> &cities, string method) {
    if (method == "roulette") return roulette_wheel_selection(population, cities);
    else return tournament_selection(population, cities);
}


vector<int> crossover(const vector<int> &p1, const vector<int> &p2) {
    int n = p1.size();
    vector<int> child(n, -1);
    int start = rand() % n;
    int end = rand() % n;
    if (start > end) swap(start, end);

    for (int i = start; i <= end; i++) child[i] = p1[i];

    int pos = (end + 1) % n;
    for (int i = 0; i < n; i++) {
        int city = p2[(end + 1 + i) % n];
        if (find(child.begin(), child.end(), city) == child.end()) {
            child[pos] = city;
            pos = (pos + 1) % n;
        }
    }
    return child;
}


void mutate(vector<int> &route, double mutation_rate) {
    if (((double) rand() / RAND_MAX) < mutation_rate) {
        int i = rand() % route.size();
        int j = rand() % route.size();
        swap(route[i], route[j]);
    }
}


vector<int> genetic_algorithm(const vector<City> &cities, string selection_method) {
    int num_cities = cities.size();
    auto population = initialize_population(30, num_cities);

    vector<int> best_route = population[0];
    double best_fit = fitness(best_route, cities);

    for (int gen = 0; gen < 100; gen++) {
        vector<vector<int>> new_population;
        for (int i = 0; i < 30; i++) {
            auto parent1 = select_parent(population, cities, selection_method);
            auto parent2 = select_parent(population, cities, selection_method);
            auto child = crossover(parent1, parent2);
            mutate(child, 0.05);
            new_population.push_back(child);

            double f = fitness(child, cities);
            if (f > best_fit) {
                best_fit = f;
                best_route = child;
            }
        }
        population = new_population;
    }
    return best_route;
}


void display_solution(const vector<int> &best_route, const vector<City> &cities, string method) {
    cout << "Best Route: ";
    for (int c : best_route) cout << c << " ";
    cout << best_route[0] << endl; // return to start
    double dist = total_distance(best_route, cities);
    cout << "Total Distance: " << dist << endl;
    cout << "Fitness: " << fitness(best_route, cities) << endl;
    cout << "Selection Method: " << method << endl;
}


int main() {
    srand(time(0));
    vector<City> cities = {
        {2,3}, {5,4}, {1,7}, {6,8}, {9,2}, {4,6}, {8,7}, {3,9}
    };

    string method;
    cout << "Enter selection method (roulette/tournament): ";
    cin >> method;

    auto best_route = genetic_algorithm(cities, method);
    display_solution(best_route, cities, method);

    return 0;
}
