#include "leetcode/problems/process-string-with-special-operations-ii.h"

#include <string>

namespace leetcode {
namespace problem_3614 {

namespace {

char processStrImpl(const std::string& s, long long k) {
  // First pass: compute the final length of result.
  long long len = 0;
  for (char c : s) {
    if (c == '*') {
      if (len > 0) --len;
    } else if (c == '#') {
      len *= 2;
    } else if (c == '%') {
      // reverse keeps length unchanged
    } else {
      ++len;
    }
  }

  if (k >= len) {
    return '.';
  }

  // Second pass (backward): trace the position k back to the original char.
  long long pos = k;
  for (int i = static_cast<int>(s.size()) - 1; i >= 0; --i) {
    char c = s[i];
    if (c == '*') {
      // After op length was len, before op it was len+1.
      ++len;
    } else if (c == '#') {
      // After op length = 2 * beforeLen. Undo duplication.
      long long beforeLen = len / 2;
      if (pos >= beforeLen) pos -= beforeLen;
      len = beforeLen;
    } else if (c == '%') {
      // Undo reversal.
      pos = len - 1 - pos;
    } else {
      // Undo an append. The appended char was at index beforeLen = len - 1.
      long long appendedIndex = len - 1;
      if (pos == appendedIndex) {
        return c;
      }
      --len;
    }
  }

  // Should be unreachable if final length > k, but guard anyway.
  return '.';
}

}  // namespace

ProcessStringWithSpecialOperationsIiSolution::
    ProcessStringWithSpecialOperationsIiSolution() {
  setMetaInfo({.id = 3614,
               .title = "Process String with Special Operations II",
               .url = "https://leetcode.com/problems/process-string-with-special-operations-ii/"});
  registerStrategy({.name = "ReverseTrace",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Simulation"}},
                   [](std::string s, long long k) -> char {
                     return processStrImpl(s, k);
                   });
}

char ProcessStringWithSpecialOperationsIiSolution::processStr(std::string s,
                                                               long long k) {
  return getSolution()(s, k);
}

}  // namespace problem_3614
}  // namespace leetcode
