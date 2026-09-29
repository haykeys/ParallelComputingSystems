#include <cstdio> 
#include <iostream> 
#include <thread>
#include <vector>
#include <random>
using namespace std;


void arrsum(int* arr, size_t n, long& result) { 
    long val = 0;

    for (int i = 0; i < n; i++) {
        val += arr[i];
    }

    result = val;
}


int main() {

    vector<long> out(2);

    // make data
    vector<int> arr(10'000'000);

    unsigned int seed = 1871;
    mt19937 gen(seed);
    uniform_int_distribution<int> dist(1, 100);

    for (int& val : arr) { // fill vector in with random numbers
        val = dist(gen);
    }

    size_t n = arr.size();
    size_t half = n / 2;

    thread thread1(arrsum, arr.data(), half, ref(out[0]));
    thread thread2(arrsum, arr.data() + half, n - half, ref(out[1]));

    thread1.join();
    thread2.join();

    long total = out[0] + out[1];

    cout << "sum = " << total << "\n";
}