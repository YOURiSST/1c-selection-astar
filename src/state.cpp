#include <state.hpp>
#include <algorithm>

TState::TState(const std::vector<TPile>& piles, uint32_t steps) : piles_(piles), steps_(steps) {
    weight_ = CountHeuristic_();
}

bool TState::operator>(const TState& other) const {
    return GetSteps() + GetWeight() > other.GetSteps() + other.GetWeight();
}

bool TState::operator<(const TState& other) const {
    return other > *this;
}

bool TState::operator==(const TState& other) const {
    return GetWeight() + GetSteps() == other.GetWeight() + GetSteps();
}

uint32_t TState::CountHeuristic_() const {
    uint32_t cardsCount = 0;
    uint32_t inversionsCount = 0;

    for (const TPile& pile : piles_) {
        cardsCount += pile.size();
        inversionsCount += CountInversions_(pile);
    }

    return cardsCount + inversionsCount;
}

uint32_t TState::CountInversions_(const TPile& pile) {
    uint32_t toRet = 0;

    for (uint32_t ft_card = 0; ft_card + 1 < pile.size(); ++ft_card) {
        for (uint32_t sc_card = ft_card + 1; sc_card < pile.size(); ++sc_card) {
            if (pile[ft_card] > pile[sc_card]) {
                ++toRet;
            }
        }
    }

    return toRet;
}

void TState::ConvertToCanonical() {  // this one allows us to dump states for a_star
    std::sort(piles_.begin(), piles_.end());
}

std::vector<TState> TState::GenerateNextStates() {
    std::vector<TState> generatedStates;

    for (uint32_t pileToGrab = 0; pileToGrab < piles_.size(); ++pileToGrab) {
        if (piles_[pileToGrab].empty()) {
            continue;
        }

        for (uint32_t pileToAdd = 0; pileToAdd < piles_.size(); ++pileToAdd) {
            if (pileToAdd == pileToGrab) {
                continue;
            }
            if (piles_[pileToGrab].back() >= piles_[pileToAdd].back()) {
                continue;
            }

            auto newPiles = piles_;
            newPiles[pileToAdd].emplace_back(newPiles[pileToGrab].back());
            newPiles[pileToGrab].pop_back();
            if (TState::IsPileDone(newPiles[pileToAdd])) {
                newPiles[pileToAdd].clear();
            }

            generatedStates.emplace_back(newPiles, steps_ + 1);
        }
    }

    return generatedStates;
}

bool TState::IsPileDone(const TPile& pile) {
    if (pile.size() != 9) {
        return false;
    }

    for (uint32_t cardInd = 0; cardInd < pile.size(); ++cardInd) {
        if (pile[cardInd] != SMALLEST_CARD + cardInd) {
            return false;
        }
    }

    return true;
}

bool TState::IsDone() const {
    for (const TPile& pile : piles_) {
        if (!pile.empty()) {
            return false;
        }
    }
    return true;
}

