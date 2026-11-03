#include <omp.h>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    // Build array of random ints

    vector<int> data(10'000'000);

    unsigned int seed = 1871;
    mt19937 gen(seed);
    uniform_int_distribution<int> dist(1, 500);

    for (int& val : data) {
        val = dist(gen);
    }   

    uniform_int_distribution<int> rand_dist(500, 1000);
    int randint = rand_dist(gen);
    data[data.size()-1] = randint;

    // Parallelize

    int min = data[0];
    int max = data[0];

    #pragma omp parallel for
    for (int i = 0; i < data.size(); i++) {
        if (data[i] < min) {
            min = data[i];
        }
        if (data[i] > max) {
            max = data[i];
        }
    }

    auto [real_min, real_max] = minmax_element(data.begin(), data.end());

    cout << "Min: " << min << ", Max: " << max << "\n";
    cout << "Real min: " << *real_min << ", Real max: " << *real_max << "\n";

}