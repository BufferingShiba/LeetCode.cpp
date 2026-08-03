#include "leetcode/problems/number-of-elapsed-seconds-between-two-times.h"

#include <string>

namespace leetcode::problem_3986 {

namespace {

int parseTimeToSeconds(const std::string& t) {
  int h = (t[0] - '0') * 10 + (t[1] - '0');
  int m = (t[3] - '0') * 10 + (t[4] - '0');
  int s = (t[6] - '0') * 10 + (t[7] - '0');
  return h * 3600 + m * 60 + s;
}

int secondsBetweenTimesImpl(std::string startTime, std::string endTime) {
  return parseTimeToSeconds(endTime) - parseTimeToSeconds(startTime);
}

}  // namespace

NumberOfElapsedSecondsBetweenTwoTimesSolution::
    NumberOfElapsedSecondsBetweenTwoTimesSolution() {
  setMetaInfo({.id = 3986,
               .title = "Number of Elapsed Seconds Between Two Times",
               .url = "https://leetcode.com/problems/number-of-elapsed-seconds-between-two-times/"});

  registerStrategy(
      {.name = "time-difference",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Time Parsing", "Math"}},
      secondsBetweenTimesImpl);
}

int NumberOfElapsedSecondsBetweenTwoTimesSolution::secondsBetweenTimes(
    std::string startTime, std::string endTime) {
  return getSolution()(std::move(startTime), std::move(endTime));
}

}  // namespace leetcode::problem_3986
