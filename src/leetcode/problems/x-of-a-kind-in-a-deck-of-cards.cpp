#include "leetcode/problems/x-of-a-kind-in-a-deck-of-cards.h"

#include <numeric>
#include <unordered_map>

namespace leetcode::problem_914 {

namespace {

bool hasGroupsSizeXImpl(std::vector<int>& deck) {
    std::unordered_map<int, int> count;
    for (int card : deck) {
        ++count[card];
    }
    int g = 0;
    for (const auto& [_, c] : count) {
        g = std::gcd(g, c);
    }
    return g >= 2;
}

}  // namespace

bool XOfAKindInADeckOfCardsSolution::hasGroupsSizeX(std::vector<int>& deck) {
    return getSolution()(deck);
}

XOfAKindInADeckOfCardsSolution::XOfAKindInADeckOfCardsSolution() {
    setMetaInfo({.id = 914,
                 .title = "X of a Kind in a Deck of Cards",
                 .url = "https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/"});
    registerStrategy(
        {.name = "gcdOfFrequencies",
         .expected = "Accepted",
         .time_complexity = "O(n)",
         .space_complexity = "O(n)",
         .tags = {"Array", "Hash Table", "Math", "Counting", "Number Theory"}},
        hasGroupsSizeXImpl);
}

}  // namespace leetcode::problem_914
