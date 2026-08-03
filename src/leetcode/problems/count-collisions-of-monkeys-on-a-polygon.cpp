#include "leetcode/problems/count-collisions-of-monkeys-on-a-polygon.h"

namespace leetcode::problem_2550 {

namespace {

constexpr int kMod = 1'000'000'007;

int monkeyMoveImpl(int n) {
  // Fast exponentiation: 2^n mod kMod
  long long base = 2;
  long long result = 1;
  int exp = n;
  while (exp > 0) {
    if (exp & 1) {
      result = (result * base) % kMod;
    }
    base = (base * base) % kMod;
    exp >>= 1;
  }
  // answer = (2^n - 2) mod kMod
  result = (result - 2 + kMod) % kMod;
  return static_cast<int>(result);
}

}  // namespace

CountCollisionsOfMonkeysOnAPolygonSolution::CountCollisionsOfMonkeysOnAPolygonSolution() {
  setMetaInfo({.id = 2550,
               .title = "Count Collisions of Monkeys on a Polygon",
               .url = "https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/"});
  registerStrategy(
      {.name = "FastExponentiation",
       .expected = "Accepted",
       .time_complexity = "O(log n)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Recursion"}},
      monkeyMoveImpl);
}

int CountCollisionsOfMonkeysOnAPolygonSolution::monkeyMove(int n) {
  return getSolution()(n);
}

}  // namespace leetcode::problem_2550
