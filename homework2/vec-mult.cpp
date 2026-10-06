#include <iostream>
#include <vector>
#include <random>
#include <chrono>

constexpr size_t SIZE = 10'000'000;

void mult(int k, int* v, int* out) { // k = scalar; b, c = vectors of ints
    for (size_t i = 0; i < SIZE; i++) {
        out[i] = k * v[i];
    }
}

void fill_random(std::vector<int>& u, std::mt19937& gen,
    std::uniform_int_distribution<int>& dist) { // c++ random number generation
    for (auto& val : u) {
        val = dist(gen);
    }
}

int main() {
    std::vector<int> v(SIZE), out(SIZE);

    std::mt19937 gen(1871);
    std::uniform_int_distribution<int> dist(-100, 100);

    fill_random(v, gen, dist);

    int k = 3;
    auto start = std::chrono::high_resolution_clock::now(); // timing how long it takes
    mult(k, v.data(), out.data());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    // add a check
    size_t pass = 0;
    for (size_t i = 0; i < SIZE; i++) {
        if (out[i] == k * v[i]) {
            pass++;
        }
    }


    std::cout << (pass > 0 ? "pass" : "fail") << ": " << pass << "\n" <<
     "Time:\n" << duration.count() << " ms\n";

    return 0;
}
