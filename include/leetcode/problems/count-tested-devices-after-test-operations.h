#ifndef LEETCODE_PROBLEMS_COUNT_TESTED_DEVICES_AFTER_TEST_OPERATIONS_H__
#define LEETCODE_PROBLEMS_COUNT_TESTED_DEVICES_AFTER_TEST_OPERATIONS_H__

#include "leetcode/core.h"

#include <functional>

namespace leetcode {
namespace problem_2960 {

using Func = std::function<int(std::vector<int>&)>;

class CountTestedDevicesAfterTestOperationsSolution
    : public SolutionBase<Func> {
 public:
  CountTestedDevicesAfterTestOperationsSolution();

  int countTestedDevices(std::vector<int>& batteryPercentages);
};

}  // namespace problem_2960
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_COUNT_TESTED_DEVICES_AFTER_TEST_OPERATIONS_H__
