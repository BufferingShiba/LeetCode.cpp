#include "leetcode/problems/reach-a-number.h"

#include <cstdlib>

namespace leetcode {
namespace problem_754 {

static int reachNumberImpl(int target) {
  int t = std::abs(target);
  int n = 0;
  long long sum = 0;
  while (sum < t || (sum - t) % 2 != 0) {
    ++n;
    sum += n;
  }
  return n;
}

ReachANumberSolution::ReachANumberSolution() {
  setMetaInfo({.id = 754,
               .title = "Reach a Number",
               .url = "https://leetcode.com/problems/reach-a-number/"});
  registerStrategy({.name = "Math",
                    .expected = "Accepted",
                    .time_complexity = "O(sqrt(N))",
                    .space_complexity = "O(1)",
                    .tags = {"Math", "Binary Search"}},
                   reachNumberImpl);
  setDefaultStrategy();
}

int ReachANumberSolution::reachNumber(int target) {
  return getSolution()(target);
}

}  // namespace problem_754
}  // namespace leetcode
