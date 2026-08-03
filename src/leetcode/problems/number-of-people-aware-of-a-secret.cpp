#include "leetcode/problems/number-of-people-aware-of-a-secret.h"

#include <vector>

namespace leetcode::problem_2327 {

namespace {

constexpr long long MOD = 1000000007LL;

int peopleAwareOfSecretImpl(int n, int delay, int forget) {
  std::vector<long long> people(n + 1, 0LL);
  std::vector<long long> prefix(n + 1, 0LL);
  people[1] = 1LL;
  prefix[1] = 1LL;
  for (int i = 2; i <= n; ++i) {
    int lo = (i - forget + 1 > 1) ? (i - forget + 1) : 1;
    int hi = i - delay;
    if (hi >= lo) {
      people[i] = (prefix[hi] - prefix[lo - 1] + MOD) % MOD;
    }
    prefix[i] = (prefix[i - 1] + people[i]) % MOD;
  }
  long long result = (prefix[n] - prefix[n - forget] + MOD) % MOD;
  return static_cast<int>(result);
}

}  // namespace

NumberOfPeopleAwareOfASecretSolution::NumberOfPeopleAwareOfASecretSolution() {
  setMetaInfo({.id = 2327,
               .title = "Number of People Aware of a Secret",
               .url = "https://leetcode.com/problems/number-of-people-aware-of-a-secret/"});
  registerStrategy(
      {.name = "dp_prefix_sum",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Dynamic Programming", "Prefix Sum"}},
      peopleAwareOfSecretImpl);
}

int NumberOfPeopleAwareOfASecretSolution::peopleAwareOfSecret(int n,
                                                              int delay,
                                                              int forget) {
  return getSolution()(n, delay, forget);
}

}  // namespace leetcode::problem_2327
