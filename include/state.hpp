#pragma once
#include <vector>
#include <hint.hpp>
class TState {
  public:
    TState(const std::vector<TPile>& piles, uint32_t steps);

    uint32_t GetSteps() const {
        return steps_;
    };
    uint32_t GetWeight() const {
        return weight_;
    };

    bool operator>(const TState& other) const;
    bool operator<(const TState& other) const;
    bool operator==(const TState& other) const;

    std::string ToString() const;
    void ConvertToCanonical();

    std::vector<TState> GenerateNextStates();
    static bool IsPileDone(const TPile& pile);

    bool IsDone() const;
  private:
    std::vector<TPile> piles_;
    uint32_t steps_;
    uint32_t weight_;

    uint32_t CountHeuristic_() const;
    static uint32_t CountInversions_(const TPile& pile);

    const static uint32_t SMALLEST_CARD = 6;
    const static uint32_t GREATEST_CARD = 14;
};