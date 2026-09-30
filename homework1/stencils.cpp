#include <cstdio>
#include <iostream>
#include <thread>
#include <array>
using namespace std;

int main() {

    std::array<std::array<int, 6>, 6> grid{};
    grid.at(1).at(1) = 100; // checks bounds

    for (const auto& row : grid) {
        for (const auto& col : row) {
            int avg = (grid[row - 1][col] + grid[row + 1][col] + grid[row][col - 1] + grid[row][col + 1]) / 4;
        }
    }

}