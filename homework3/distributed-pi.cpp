#include <omp.h>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main() {

    int ths = omp_get_num_threads();

    int inside_circle = 0;
    long int iter = 10000;

    #pragma omp parallel for
    for (int i = 0; i < iter; i++) {

        unsigned int seed = 2026 + ths;
        mt19937 gen(seed);

        uniform_real_distribution<double> xdist(0.0, 1.0);
        uniform_real_distribution<double> ydist(0.0, 1.0);

        double x = xdist(gen);
        double y = ydist(gen);

        if ((x * x + y * y) <= 1.0) {
            inside_circle++;
        }
    }

    double pi = 4.0 * ((double)inside_circle / (double)iter);
    
    cout << "pi approximation = " << pi << "\n";

}