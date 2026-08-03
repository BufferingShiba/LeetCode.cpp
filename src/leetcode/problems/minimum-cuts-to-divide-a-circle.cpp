#include "leetcode/problems/minimum-cuts-to-divide-a-circle.h"

namespace leetcode::problem_2481 {
namespace {

int numberOfCutsImpl(int n) {
  if (n == 1) {
    return 0;
  }
  return (n % 2 == 0) ? (n / 2) : n;
}

}  // namespace

MinimumCutsToDivideACircleSolution::MinimumCutsToDivideACircleSolution() {
  setMetaInfo({
      .id = 2481,
      .title = "Minimum Cuts to Divide a Circle",
      .url = "https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/",
  });
  registerStrategy(
      {
          .name = "math",
          .expected = "Accepted",
          .time_complexity = "O(1)",
          .space_complexity = "O(1)",
          .tags = {"Math", "Geometry"},
      },
      numberOfCutsImpl);
}

}  // namespace leetcode::problem_2481
