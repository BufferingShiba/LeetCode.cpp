#include "leetcode/problems/count-tested-devices-after-test-operations.h"

#include <vector>

namespace leetcode {
namespace problem_2960 {

namespace {

int countTestedDevicesImpl(std::vector<int>& batteryPercentages) {
  int tested = 0;
  for (int p : batteryPercentages) {
    if (p - tested > 0) {
      ++tested;
    }
  }
  return tested;
}

}  // namespace

CountTestedDevicesAfterTestOperationsSolution::
    CountTestedDevicesAfterTestOperationsSolution() {
  setMetaInfo({.id = 2960,
               .title = "Count Tested Devices After Test Operations",
               .url = "https://leetcode.com/problems/count-tested-devices-after-test-operations/"});
  registerStrategy(
      {.name = "Simulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(1)",
       .tags = {"Array", "Simulation", "Counting"}},
      countTestedDevicesImpl);
}

int CountTestedDevicesAfterTestOperationsSolution::countTestedDevices(
    std::vector<int>& batteryPercentages) {
  return getSolution()(batteryPercentages);
}

}  // namespace problem_2960
}  // namespace leetcode
