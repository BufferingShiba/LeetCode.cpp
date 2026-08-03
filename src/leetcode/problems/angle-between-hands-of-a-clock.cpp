#include "leetcode/problems/angle-between-hands-of-a-clock.h"

#include <algorithm>
#include <cmath>

namespace leetcode {
namespace problem_1344 {

namespace {

double angleClockImpl(int hour, int minutes) {
  static constexpr double kMinuteAnglePerMinute = 6.0;   // 360° / 60
  static constexpr double kHourAnglePerHour = 30.0;      // 360° / 12
  static constexpr double kHourAnglePerMinute = 0.5;     // 30° / 60

  double minuteAngle = minutes * kMinuteAnglePerMinute;
  double hourAngle = (hour % 12) * kHourAnglePerHour + minutes * kHourAnglePerMinute;

  double diff = std::abs(hourAngle - minuteAngle);
  return std::min(diff, 360.0 - diff);
}

}  // namespace

AngleBetweenHandsOfAClockSolution::AngleBetweenHandsOfAClockSolution() {
  setMetaInfo({.id = 1344,
               .title = "Angle Between Hands of a Clock",
               .url = "https://leetcode.com/problems/angle-between-hands-of-a-clock/"});

  registerStrategy({.name = "Direct Math",
                    .expected = "Accepted",
                    .time_complexity = "O(1)",
                    .space_complexity = "O(1)",
                    .tags = {"Math"}},
                   angleClockImpl);
}

}  // namespace problem_1344
}  // namespace leetcode
