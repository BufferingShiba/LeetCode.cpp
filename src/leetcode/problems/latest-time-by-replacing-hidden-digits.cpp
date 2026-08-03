#include "leetcode/problems/latest-time-by-replacing-hidden-digits.h"

namespace leetcode {
namespace problem_1736 {

namespace {

std::string maximumTimeImpl(std::string time) {
  if (time[0] == '?') {
    time[0] = (time[1] != '?' && time[1] > '3') ? '1' : '2';
  }
  if (time[1] == '?') {
    time[1] = (time[0] == '2') ? '3' : '9';
  }
  if (time[3] == '?') {
    time[3] = '5';
  }
  if (time[4] == '?') {
    time[4] = '9';
  }
  return time;
}

}  // namespace

LatestTimeByReplacingHiddenDigitsSolution::LatestTimeByReplacingHiddenDigitsSolution() {
  setMetaInfo({1736, "Latest Time by Replacing Hidden Digits",
               "https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/"});
  registerStrategy(
      {"greedy", "Accepted", "O(1)", "O(1)", {"String", "Greedy"},
       "Fill each position with the maximum possible digit while keeping time valid."},
      maximumTimeImpl);
}

std::string LatestTimeByReplacingHiddenDigitsSolution::maximumTime(std::string time) {
  return getSolution()(time);
}

}  // namespace problem_1736
}  // namespace leetcode
