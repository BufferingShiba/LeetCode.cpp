#include <algorithm>
#include <string>
#include <vector>

#include "leetcode/problems/largest-number-after-digit-swaps-by-parity.h"

namespace leetcode {
namespace problem_2231 {

namespace {

int largestIntegerImpl(int num) {
  std::string s = std::to_string(num);
  std::vector<int> oddDigits;
  std::vector<int> evenDigits;
  for (char c : s) {
    int d = c - '0';
    if (d % 2 == 0) {
      evenDigits.push_back(d);
    } else {
      oddDigits.push_back(d);
    }
  }
  std::sort(oddDigits.rbegin(), oddDigits.rend());
  std::sort(evenDigits.rbegin(), evenDigits.rend());
  std::string result;
  int oi = 0, ei = 0;
  for (char c : s) {
    int d = c - '0';
    if (d % 2 == 0) {
      result.push_back(static_cast<char>('0' + evenDigits[ei++]));
    } else {
      result.push_back(static_cast<char>('0' + oddDigits[oi++]));
    }
  }
  return std::stoi(result);
}

}  // namespace

LargestNumberAfterDigitSwapsByParitySolution::
    LargestNumberAfterDigitSwapsByParitySolution() {
  setMetaInfo({.id = 2231,
               .title = "Largest Number After Digit Swaps by Parity",
               .url = "https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/"});
  StrategyMetadata meta;
  meta.name = "paritySorting";
  meta.expected = "Accepted";
  meta.time_complexity = "O(n log n)";
  meta.space_complexity = "O(n)";
  meta.tags = {"Sorting"};
  registerStrategy(meta, largestIntegerImpl);
}

int LargestNumberAfterDigitSwapsByParitySolution::largestInteger(int num) {
  return getSolution()(num);
}

}  // namespace problem_2231
}  // namespace leetcode
