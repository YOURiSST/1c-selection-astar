#include <iostream>
#include <game.hpp>
int main() {
    std::vector<TPile> startPiles = {
        {14, 13, 12, 11, 10, 9, 8, 7, 6},
        {14, 13, 12, 11, 10, 9, 8, 7, 6},
        {14, 13, 12, 11, 10, 9, 8, 7, 6},
        {14, 13, 12, 11, 10, 9, 8, 7, 6},
        {14, 13, 12, 11, 10, 9, 8, 7, 6},
        {14, 13, 12, 11, 10, 9, 8, 7, 6},
        {14, 13, 12, 11, 10, 9, 8, 7, 6},
        {14, 13, 12, 11, 10, 9, 8, 7, 6},
    };

    TGame game{startPiles};
    std::cout << game.SolveGame();
    return 0;
}