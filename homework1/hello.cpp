#include <cstdio> // C
#include <iostream> // C++ lib
#include <thread>

int hello(int num) {
	std::cout << "Hello from " << num << std::endl;
	return num;
}


int main() {
	auto c = std::thread::hardware_concurrency();

	printf("Hello, world! %d\n", c);

	std::thread thread1(hello, 1);
	std::thread thread2(hello, 2);

	thread1.join();
	thread2.join();

	std::cout << "Hola, mundo! " << 1 << std::endl;
}
