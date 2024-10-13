#pragma once

#include <hint.hpp>
#include <state.hpp>
#include <a_star.hpp>
#include <vector>

class TGame {
  public:
    explicit TGame(const std::vector<TPile>& toCreateState) : Algo_(toCreateState) {}
    std::string SolveGame();
  private:
    TAStarAlgo Algo_;
};