#include <iostream>
#include <vector>
#include <future>
#include <random>
#include <chrono>
#include <algorithm> // needed for min and max functions
#include <utility> // needed to return minmax output as pair


template <typename Iterator>
auto parallel_task(Iterator begin, Iterator end) {
    auto length = std::distance(begin, end);       

    if (length < 100'000) { // base case
        auto [min, max] = std::minmax_element(begin, end); 
        return std::make_pair(*min, *max); // first = min, second = max
    }

    Iterator mid = begin + length / 2;

    auto right_future = std::async(std::launch::async, parallel_task<Iterator>, mid, end); 
    auto left_result = parallel_task(begin, mid); 

    auto right_result = right_future.get();

    int overall_min = std::min(left_result.first, right_result.first);
    int overall_max = std::max(left_result.second, right_result.second);

    return std::make_pair(overall_min, overall_max);
}

int main() {
    std::vector<int> data(10'000'000);

    unsigned int seed = 1871;
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> dist(1, 100);

    for (int& val : data) {
        val = dist(gen);
    }

    // TIMING

    auto start = std::chrono::high_resolution_clock::now();
    auto [min, max] = parallel_task(data.begin(), data.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;


    std::cout << "Min: " << min << ", Max: " << max << "\n" << "Time: " << duration.count() << "\n";
}
