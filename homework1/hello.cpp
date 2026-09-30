#include <cstdio> // C
#include <iostream> // C++ lib
#include <thread>
#include <vector>
using namespace std;

int hello(int num) {
	cout << "Hello from " << num << endl;
	return num;
}


int main() {
	auto c = std::thread::hardware_concurrency();

	printf("Hello, world! %d\n", c);

	vector<thread> threads;

	for (auto i = 0; i < c; i++) {
		threads.emplace_back(hello, i);
	}

	for (thread& t : threads) {
		t.join();
	}

	cout << "Hola, mundo! This is the end. " << endl;
}

