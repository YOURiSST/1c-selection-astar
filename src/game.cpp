#include <game.hpp>
#include <iostream>

std::string TGame::SolveGame() {
    auto now = Algo_.AStar();
    if (now == std::nullopt) {
        return "NO SOLUTION FOUND";
    } else {
        return "WE CAN DO THIS STATE IN " + std::to_string( now->GetSteps() ) + " STEPS";
    }
}