#include "leetcode/problems/preimage-size-of-factorial-zeroes-function.h"

namespace leetcode {
namespace problem_793 {

namespace {

long long countTrailingZeroes(long long x) {
  long long cnt = 0;
  while (x >= 5) {
    x /= 5;
    cnt += x;
  }
  return cnt;
}

}  // namespace

int preimageSizeFZFImpl(int k) {
  if (k < 0) return 0;
  // f(x) is monotone non-decreasing. Find smallest x with f(x) >= k.
  long long low = 0, high = 5LL * (k + 1) + 5;  // f(high) is comfortably >= k
  while (low < high) {
    long long mid = low + (high - low) / 2;
    if (countTrailingZeroes(mid) >= k) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  // If f(low) == k, then f(low+1)..f(low+4) are all equal to k => answer 5.
  // Otherwise k was skipped => answer 0.
  return countTrailingZeroes(low) == k ? 5 : 0;
}

int preimageSizeFZF(int k) { return preimageSizeFZFImpl(k); }

}  // namespace problem_793
}  // namespace leetcode
