#include <iostream>
#include <vector>
#include <random>
#include <chrono>

constexpr size_t SIZE = 10'000'000;

void add(int* a, int* b, int* c) { // 3 arrays: a, b, c
    for (size_t i = 0; i < SIZE; i++) {
        c[i] = a[i] + b[i];
    }
}

void fill_random(std::vector<int>& v, std::mt19937& gen,
    std::uniform_int_distribution<int>& dist) { // c++ random number generation
    for (auto& val : v) {
        val = dist(gen);
    }
}

int main() {
    std::vector<int> a(SIZE), b(SIZE), c(SIZE);

    std::mt19937 gen(1871);
    std::uniform_int_distribution<int> dist(-100, 100);

    fill_random(a, gen, dist);
    fill_random(b, gen, dist);

    auto start = std::chrono::high_resolution_clock::now(); // timing how long it takes
    add(a.data(), b.data(), c.data());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    // add a check
    size_t pass = 0;
    for (size_t i = 0; i < SIZE; i++) {
        if (c[i] == a[i] + b[i]) {
            pass++;
        }
    }


    std::cout << (pass > 0 ? "pass" : "fail") << ": " << pass << "\n" <<
     "Time:\n" << duration.count() << " ms\n";

    return 0;
}
