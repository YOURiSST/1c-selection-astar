#include <iostream>
#include <game.hpp>
int main() {
    std::vector<TPile> startPiles(8, TPile(9));

    for (auto& pile : startPiles) {
        for (auto& card : pile) {
            std::cin >> card;
        }
    }


    TGame game{startPiles};
    std::cout << game.SolveGame();
    return 0;
}