#include <gtest/gtest.h>
#include "leetcode/problems/design-a-number-container-system.h"

namespace leetcode {
namespace problem_2349 {
namespace {

using ::testing::TestWithParam;
using ::testing::Values;

using DesignANumberContainerSystemTest = TestWithParam<int>;

TEST_P(DesignANumberContainerSystemTest, Example1) {
  NumberContainers nc;
  EXPECT_EQ(nc.find(10), -1);
  nc.change(2, 10);
  nc.change(1, 10);
  nc.change(3, 10);
  nc.change(5, 10);
  EXPECT_EQ(nc.find(10), 1);
  nc.change(1, 20);
  EXPECT_EQ(nc.find(10), 2);
}

INSTANTIATE_TEST_SUITE_P(
    NumberContainersTests,
    DesignANumberContainerSystemTest,
    Values(0));

}  // namespace
}  // namespace problem_2349
}  // namespace leetcode
