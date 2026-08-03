#include "leetcode/problems/number-of-valid-clock-times.h"

#include <string>

namespace leetcode {
namespace problem_2437 {

namespace {

int countTimeImpl(std::string time) {
  int count = 1;

  // hours: time[0] time[1]
  if (time[0] == '?' && time[1] == '?') {
    count *= 24;
  } else if (time[0] == '?') {
    count *= (time[1] <= '3') ? 3 : 2;  // h1 in 0..2 if h2<=3, else 0..1
  } else if (time[1] == '?') {
    count *= (time[0] == '2') ? 4 : 10;  // h2 in 0..3 if h1=='2', else 0..9
  }

  // minutes: time[3] time[4]
  if (time[3] == '?') {
    count *= 6;  // m1 in 0..5
  }
  if (time[4] == '?') {
    count *= 10;  // m2 in 0..9
  }

  return count;
}

}  // namespace

NumberOfValidClockTimesSolution::NumberOfValidClockTimesSolution() {
  setMetaInfo({.id = 2437,
               .title = "Number of Valid Clock Times",
               .url = "https://leetcode.com/problems/number-of-valid-clock-times/"});
  registerStrategy({.name = "Enumeration",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"String", "Enumeration"}},
                   countTimeImpl);
}

int NumberOfValidClockTimesSolution::countTime(std::string time) {
  return getSolution()(time);
}

}  // namespace problem_2437
}  // namespace leetcode
