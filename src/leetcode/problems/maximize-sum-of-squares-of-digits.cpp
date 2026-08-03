#include "leetcode/problems/maximize-sum-of-squares-of-digits.h"

#include <string>

namespace leetcode {
namespace problem_3723 {

// Math + Greedy.
// The sum-of-squares objective is convex; over the simplex {0<=d_i<=9, sum=S}
// the maximum is attained at an extreme point with at most one digit strictly
// inside (0,9): use as many 9s as possible (each unit of digit-s sum gives the
// largest square contribution when concentrated in a 9), one remainder r, and
// zeros for the rest. Sorting digits descending yields the maximum integer.
static std::string maxSumOfSquaresImpl(int num, int sum) {
  // Feasibility: each of num digits contributes at most 9 to the sum.
  if (sum > 9LL * num) {
    return "";
  }
  long long q = sum / 9;
  int r = sum % 9;

  std::string result;
  result.reserve(static_cast<size_t>(num));
  result.append(static_cast<size_t>(q), '9');
  if (r > 0) {
    result.push_back(static_cast<char>('0' + r));
  }
  const size_t used = static_cast<size_t>(q) + (r > 0 ? 1u : 0u);
  result.append(static_cast<size_t>(num) - used, '0');
  return result;
}

MaximizeSumOfSquaresOfDigitsSolution::MaximizeSumOfSquaresOfDigitsSolution() {
  setMetaInfo({.id = 3723,
               .title = "Maximize Sum of Squares of Digits",
               .url = "https://leetcode.com/problems/maximize-sum-of-squares-of-digits/"});
  registerStrategy({.name = "math-greedy",
                    .expected = "Accepted",
                    .time_complexity = "O(num)",
                    .space_complexity = "O(num)",
                    .tags = {"Math", "Greedy"}},
                   maxSumOfSquaresImpl);
}

std::string MaximizeSumOfSquaresOfDigitsSolution::maxSumOfSquares(int num, int sum) {
  return getSolution()(num, sum);
}

}  // namespace problem_3723
}  // namespace leetcode
