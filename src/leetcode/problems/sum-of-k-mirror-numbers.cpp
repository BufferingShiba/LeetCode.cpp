#include "leetcode/problems/sum-of-k-mirror-numbers.h"
#include <string>
#include <algorithm>

namespace leetcode {
namespace problem_2081 {
namespace {

bool isKMirror(long long val, int k) {
  // Build base-k representation (digit by digit, order irrelevant for
  // palindrome check since an inversion is symmetric).
  std::string krep;
  long long v = val;
  while (v > 0) {
    krep.push_back(static_cast<char>('0' + v % k));
    v /= k;
  }
  int l = 0, r = static_cast<int>(krep.size()) - 1;
  while (l < r) {
    if (krep[l] != krep[r]) return false;
    ++l;
    --r;
  }
  return true;
}

// Strategy: enumerate decimal palindromes by half-length (which guarantees
// non-decreasing numeric order), and test each for base-k palindrome.
long long kMirrorImpl(int k, int n) {
  long long sum = 0;
  int count = 0;
  for (int h = 1;; ++h) {
    long long start = 1;
    for (int i = 0; i < h - 1; ++i) start *= 10;
    long long end = start * 10;
    // parity 0 -> odd length (2h-1), parity 1 -> even length (2h)
    for (int parity = 0; parity < 2; ++parity) {
      for (long long left = start; left < end; ++left) {
        std::string s = std::to_string(left);
        std::string rev = (parity == 0) ? s.substr(0, h - 1) : s;
        std::reverse(rev.begin(), rev.end());
        std::string pal = s + rev;
        long long val = std::stoll(pal);
        if (isKMirror(val, k)) {
          sum += val;
          if (++count == n) return sum;
        }
      }
    }
  }
}

}  // namespace

SumOfKMirrorNumbersSolution::SumOfKMirrorNumbersSolution() {
  setMetaInfo({.id = 2081,
               .title = "Sum of k-Mirror Numbers",
               .url = "https://leetcode.com/problems/sum-of-k-mirror-numbers/"});
  registerStrategy({.name = "palindrome-enumeration",
                    .expected = "Accepted",
                    .time_complexity = "O(P)",
                    .space_complexity = "O(log val)",
                    .tags = {"Math", "Enumeration"}},
                   kMirrorImpl);
}

long long SumOfKMirrorNumbersSolution::kMirror(int k, int n) {
  return getSolution()(k, n);
}

}  // namespace problem_2081
}  // namespace leetcode
