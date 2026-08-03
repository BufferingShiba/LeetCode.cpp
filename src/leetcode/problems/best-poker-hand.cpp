#include "leetcode/problems/best-poker-hand.h"

#include <array>

namespace leetcode {
namespace problem_2347 {

namespace {

std::string bestHandImpl(std::vector<int>& ranks, std::vector<char>& suits) {
  // Check flush first: all suits identical.
  bool flush = true;
  for (int i = 1; i < 5; ++i) {
    if (suits[i] != suits[0]) {
      flush = false;
      break;
    }
  }
  if (flush) {
    return "Flush";
  }

  std::array<int, 14> cnt{};
  int maxCnt = 0;
  for (int r : ranks) {
    maxCnt = std::max(maxCnt, ++cnt[r]);
  }
  if (maxCnt >= 3) {
    return "Three of a Kind";
  }
  if (maxCnt == 2) {
    return "Pair";
  }
  return "High Card";
}

}  // namespace

BestPokerHandSolution::BestPokerHandSolution() {
  setMetaInfo({.id = 2347,
               .title = "Best Poker Hand",
               .url = "https://leetcode.com/problems/best-poker-hand/"});
  registerStrategy({.name = "Counting",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Counting", "Hash Table"}},
                   bestHandImpl);
}

std::string BestPokerHandSolution::bestHand(std::vector<int>& ranks,
                                            std::vector<char>& suits) {
  return getSolution()(ranks, suits);
}

}  // namespace problem_2347
}  // namespace leetcode
