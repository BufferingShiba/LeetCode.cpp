#include "leetcode/problems/count-good-meals.h"

#include <array>
#include <unordered_map>
#include <utility>

namespace leetcode {
namespace problem_1711 {
namespace {

// For each element x, a good meal partner y satisfies x + y == power of two.
// Since values are <= 2^20, the maximum possible sum is 2^21.
// Hence the relevant powers of two are 1, 2, 4, ..., 2^21.
constexpr int kMaxPower = 22;   // number of powers in [1, 2^21]
constexpr long long kMod = 1000000007LL;

// Build the list of powers of two once.
std::array<long long, kMaxPower> MakePowers() {
  std::array<long long, kMaxPower> powers{};
  long long v = 1;
  for (int i = 0; i < kMaxPower; ++i) {
    powers[i] = v;
    v <<= 1;
  }
  return powers;
}

int CountGoodMealsImpl(std::vector<int>& deliciousness) {
  static const std::array<long long, kMaxPower> kPowers = MakePowers();

  std::unordered_map<int, long long> count;
  long long result = 0;

  for (int x : deliciousness) {
    long long lx = x;
    for (long long p : kPowers) {
      long long need = p - lx;
      if (need >= 0) {
        auto it = count.find(static_cast<int>(need));
        if (it != count.end()) {
          result = (result + it->second) % kMod;
        }
      }
    }
    ++count[x];
  }

  return static_cast<int>(result);
}

}  // namespace

CountGoodMealsSolution::CountGoodMealsSolution() {
  setMetaInfo({.id = 1711,
               .title = "Count Good Meals",
               .url = "https://leetcode.com/problems/count-good-meals/"});
  registerStrategy({.name = "hash-table",
                    .expected = "Accepted",
                    .time_complexity = "O(22*n)",
                    .space_complexity = "O(n)",
                    .tags = {"Array", "Hash Table"}},
                   CountGoodMealsImpl);
}

int CountGoodMealsSolution::countPairs(std::vector<int>& deliciousness) {
  return getSolution()(deliciousness);
}

}  // namespace problem_1711
}  // namespace leetcode
