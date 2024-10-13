#pragma once

#include <state.hpp>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <optional>

class TAStarAlgo {
  public:
    explicit TAStarAlgo(TState start);
    explicit TAStarAlgo(const std::vector<TPile>& toCreateState);
    std::optional<TState> AStar();

  private:
    std::priority_queue<TState, std::vector<TState>, std::greater<TState>> Transitions_;
    std::set<TState> UsedStates_;
    TState Start_;
};