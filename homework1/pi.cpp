#include <cstdio> 
#include <iostream> 
#include <thread>
#include <vector>
#include <random>
using namespace std;

void quadrant(int iter, double xmin, double xmax, double ymin, double ymax, double& result) {
    
    unsigned int seed = 1871;
    mt19937 gen(seed);
    int inside_circle = 0;

    uniform_real_distribution<double> xdist(xmin, xmax);
    uniform_real_distribution<double> ydist(ymin, ymax);

    for(int i = 0; i < iter; i++) {
        double x = xdist(gen);
        double y = ydist(gen);

        if ((x * x + y * y) <= 1.0) {
            inside_circle++;
        }
    }
    result = inside_circle;
}

int main() {
    double x, y;
    long int iter = 1000;
    vector<double> out(4);
    // vector<thread> threads

    // unsigned int seed = 1871;
    // mt19937 gen(seed);
    // uniform_int_distribution<double> dist(0.0, 1.0);

    thread q1thread(quadrant, iter, 0.0, 1.0, 0.0, 1.0, ref(out[0]));
    thread q2thread(quadrant, iter, -1.0, 0.0, 0.0, 1.0, ref(out[1]));
    thread q3thread(quadrant, iter, -1.0, 0.0, -1.0, 0.0, ref(out[2]));
    thread q4thread(quadrant, iter, 0.0, 1.0, -1.0, 0.0, ref(out[3]));

    // for (thread& t : threads) {
	// 	t.join();
	// }

    q1thread.join();
    q2thread.join();
    q3thread.join();
    q4thread.join();

    long inside = (out[0] + out[1] + out[2] + out[3]);
    long total = 4 * iter;
    double pi = 4.0 * (static_cast<double>(inside) / static_cast<double>(total));

    cout << "pi approximation = " << pi << "\n";

}