#include <gtest/gtest.h>

#include "leetcode/problems/design-parking-system.h"

namespace leetcode::problem_1603 {

class DesignParkingSystemTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override { (void)GetParam(); }
};

// 官方示例：构造 (1, 1, 0)
TEST_P(DesignParkingSystemTest, Example1) {
  DesignParkingSystemSolution system(1, 1, 0);
  EXPECT_TRUE(system.addCar(1));   // big 槽位可用
  EXPECT_TRUE(system.addCar(2));   // medium 槽位可用
  EXPECT_FALSE(system.addCar(3));  // small 槽位为 0
  EXPECT_FALSE(system.addCar(1));  // big 已被占用
}

INSTANTIATE_TEST_SUITE_P(DesignParkingSystemTests, DesignParkingSystemTest,
                         ::testing::Values(0));

}  // namespace leetcode::problem_1603
