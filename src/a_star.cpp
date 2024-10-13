#include <a_star.hpp>
#include <utility>
#include <iostream>
TAStarAlgo::TAStarAlgo(TState start) : Start_(std::move(start)) {
    Start_.ConvertToCanonical();
    Transitions_.emplace(Start_);
}

TAStarAlgo::TAStarAlgo(const std::vector<TPile>& toCreateState) : Start_(toCreateState, 0) {
    Start_.ConvertToCanonical();
    Transitions_.emplace(Start_);
}

std::optional<TState> TAStarAlgo::AStar() {
    const uint32_t MAX_CYCLE_MOVES = 1000000;
    uint32_t currentMovesCounter = 0;
    while (!Transitions_.empty() && currentMovesCounter < MAX_CYCLE_MOVES) {
        ++currentMovesCounter;

        auto current = Transitions_.top();
        if (current.IsDone()) {
            return current;
        }
        Transitions_.pop();
        UsedStates_.emplace(current);

        for (TState& nextState : current.GenerateNextStates()) {
            nextState.ConvertToCanonical();
            if (UsedStates_.contains(nextState)) {
                continue;
            }
            Transitions_.emplace(nextState);
        }
    }

    return std::nullopt;
}
