#include "leetcode/problems/alice-and-bob-playing-flower-game.h"

namespace leetcode {
namespace problem_3021 {

static long long flowerGameImpl(int n, int m) {
  long long n_odd = (n + 1LL) / 2;
  long long n_even = n / 2LL;
  long long m_odd = (m + 1LL) / 2;
  long long m_even = m / 2LL;
  return n_odd * m_even + n_even * m_odd;
}

AliceAndBobPlayingFlowerGameSolution::AliceAndBobPlayingFlowerGameSolution() {
  setMetaInfo({.id = 3021, .title = "Alice and Bob Playing Flower Game",
               .url = "https://leetcode.com/problems/alice-and-bob-playing-flower-game/"});
  registerStrategy({.name = "math",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math"}},
                   flowerGameImpl);
  setDefaultStrategy();
}

long long AliceAndBobPlayingFlowerGameSolution::flowerGame(int n, int m) {
  return getSolution()(n, m);
}

}  // namespace problem_3021
}  // namespace leetcode
