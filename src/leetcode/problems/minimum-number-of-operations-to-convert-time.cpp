#include "leetcode/problems/minimum-number-of-operations-to-convert-time.h"

namespace leetcode {
namespace problem_2224 {

namespace {

int toMinutes(const std::string& time) {
  int hh = (time[0] - '0') * 10 + (time[1] - '0');
  int mm = (time[3] - '0') * 10 + (time[4] - '0');
  return hh * 60 + mm;
}

int convertTimeImpl(std::string current, std::string correct) {
  int diff = toMinutes(correct) - toMinutes(current);
  int ops = 0;
  ops += diff / 60;
  diff %= 60;
  ops += diff / 15;
  diff %= 15;
  ops += diff / 5;
  diff %= 5;
  ops += diff;
  return ops;
}

}  // namespace

MinimumNumberOfOperationsToConvertTimeSolution::MinimumNumberOfOperationsToConvertTimeSolution() {
  setMetaInfo({.id = 2224,
                .title = "Minimum Number of Operations to Convert Time",
                .url = "https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/"});
  registerStrategy({.name = "Greedy",
                     .expected = "Accepted",
                     .time_complexity = "O(1)",
                     .space_complexity = "O(1)",
                     .tags = {"String", "Greedy"}},
                   convertTimeImpl);
}

int MinimumNumberOfOperationsToConvertTimeSolution::convertTime(std::string current,
                                                                 std::string correct) {
  return getSolution()(std::move(current), std::move(correct));
}

}  // namespace problem_2224
}  // namespace leetcode
