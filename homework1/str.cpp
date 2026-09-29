#include <cstdio>
#include <iostream>
#include <thread>
#include <string>
using namespace std;

void toUpper(string& str, size_t start, size_t end) {
    
    for (char& c : str) {
        int ch = c;
        if (ch >= 97 && ch <= 122) {
            ch -= 32;
        }
        c = ch;
    }
}


int main() {

    string str = "Hayley!? Lucy";

    size_t n = str.size();
    size_t mid = n / 2;

    thread thread1(toUpper, ref(str), 0, mid);
    thread thread2(toUpper, ref(str), mid, str.size());

    thread1.join();
    thread2.join();

    cout << str << "\n";
}