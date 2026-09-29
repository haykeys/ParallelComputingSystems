#include <stdio.h>
#include <stdlib.h>

int main() {
    double x, y;
    long int iterations = 67;
    int inside_circle = 0;

    for(int i = 0; i < iterations; i++) {
        double x = rand()/RAND_MAX;
        double y = rand()/RAND_MAX;

        if ((x * x + y * y) <= 1.0) {
            inside_circle++;
        }
    }
    
    double approx = (double)4.0 * (inside_circle/iterations);
    printf("pi approximation: %.4f\n", approx);

    return approx;
}

// smth is wrong fix
