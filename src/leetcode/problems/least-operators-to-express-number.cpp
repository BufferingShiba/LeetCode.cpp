#include "leetcode/problems/least-operators-to-express-number.h"

#include <algorithm>
#include <cstdint>
#include <vector>

namespace leetcode {
namespace problem_964 {
namespace {

// The target can be written as sum of signed power terms e_j * x^j.
// Any valid expression's operator count equals:
//     W - 1,   where W = sum_j |e_j| * c_j,
// with c_0 = 2 (a term x^0 = 1 needs one division x/x plus a sign) and
// c_j = j for j >= 1 (a term x^j needs j-1 multiplications plus a sign).
//
// We find the integer coefficients {e_j} (allowing negative / borrow) that
// minimize W using a digit DP over the x-ary digits of target, enumerating
// every adjacent-digit borrow combination. This guarantees the global optimum.
int solveViaBitDp(long long x, long long target) {
  // Extract x-ary digits, least-significant first.
  std::vector<long long> d;
  long long t = target;
  while (t > 0) {
    d.push_back(t % x);
    t /= x;
  }
  // Append a sentinel zero digit so a final borrow can be absorbed.
  d.push_back(0);

  const long long INF = static_cast<long long>(1e18);
  // dp[j][b]: min accumulated weight over bits 0..j with borrow b_j to the
  // next-higher digit (b_j in {0,1}).
  // cost of coefficient e_j at power j: |e_j| * c_j.
  auto weight = [](long long e, long long j) -> long long {
    long long c = (j == 0) ? 2 : j;
    return static_cast<long long>(std::llabs(e)) * c;
  };

  // First digit (j = 0), with implicit borrow_in = 0.
  long long dp_prev[2];
  for (long long b = 0; b < 2; ++b) {
    long long e = d[0] - b * x;  // b_{-1}=0
    dp_prev[b] = weight(e, 0);
  }

  for (std::size_t j = 1; j < d.size(); ++j) {
    long long dp_cur[2] = {INF, INF};
    for (long long b_prev = 0; b_prev < 2; ++b_prev) {
      if (dp_prev[b_prev] >= INF) continue;
      for (long long b = 0; b < 2; ++b) {
        long long e = d[j] + b_prev - b * x;
        long long cand = dp_prev[b_prev] + weight(e, static_cast<long long>(j));
        dp_cur[b] = std::min(dp_cur[b], cand);
      }
    }
    dp_prev[0] = dp_cur[0];
    dp_prev[1] = dp_cur[1];
  }

  // After the sentinel digit, the borrow must be zero.
  long long W = dp_prev[0];
  // At least one term exists (target >= 1), so W >= 1; answer = W - 1.
  return static_cast<int>(W - 1);
}

}  // namespace

int LeastOperatorsToExpressNumberSolution::leastOpsExpressTargetImpl(int x,
                                                                     int target) {
  return solveViaBitDp(static_cast<long long>(x),
                       static_cast<long long>(target));
}

}  // namespace problem_964
}  // namespace leetcode
