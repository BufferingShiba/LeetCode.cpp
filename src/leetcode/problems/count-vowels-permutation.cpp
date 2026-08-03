#include "leetcode/problems/count-vowels-permutation.h"

namespace leetcode::problem_1220 {
namespace {

constexpr long long kMod = 1000000007LL;

int countVowelPermutationImpl(int n) {
  // Indices: 0:a, 1:e, 2:i, 3:o, 4:u
  long long a = 1, e = 1, i = 1, o = 1, u = 1;
  for (int len = 1; len < n; ++len) {
    long long na = (e + i + u) % kMod;
    long long ne = (a + i) % kMod;
    long long ni = (e + o) % kMod;
    long long no = i % kMod;
    long long nu = (i + o) % kMod;
    a = na;
    e = ne;
    i = ni;
    o = no;
    u = nu;
  }
  return static_cast<int>((a + e + i + o + u) % kMod);
}

}  // namespace

CountVowelsPermutationSolution::CountVowelsPermutationSolution() {
  this->setMetaInfo({.id = 1220,
                     .title = "Count Vowels Permutation",
                     .url = "https://leetcode.com/problems/count-vowels-permutation/"});
  this->registerStrategy(
      {.name = "dp-rolling-array",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Dynamic Programming"}},
      countVowelPermutationImpl);
}

}  // namespace leetcode::problem_1220
