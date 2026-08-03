#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/add-strings.h"

namespace leetcode {
namespace problem_415 {

class AddStringsTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  AddStringsSolution solution;
};

TEST_P(AddStringsTest, Example1) {
  EXPECT_EQ(solution.addStrings("11", "123"), "134");
}

TEST_P(AddStringsTest, Example2) {
  EXPECT_EQ(solution.addStrings("456", "77"), "533");
}

TEST_P(AddStringsTest, Example3) {
  EXPECT_EQ(solution.addStrings("0", "0"), "0");
}

TEST_P(AddStringsTest, SelfAuthoredCarryPropagation) {
  EXPECT_EQ(solution.addStrings("999", "1"), "1000");
}

TEST_P(AddStringsTest, SelfAuthoredEqualLengthCarry) {
  EXPECT_EQ(solution.addStrings("19", "81"), "100");
}

TEST_P(AddStringsTest, SelfAuthoredLongNumbers) {
  EXPECT_EQ(solution.addStrings("123456789", "987654321"), "1111111110");
}

INSTANTIATE_TEST_SUITE_P(
    AddStringsTestSuite, AddStringsTest,
    ::testing::ValuesIn(AddStringsSolution().getStrategyNames()));

}  // namespace problem_415
}  // namespace leetcode
