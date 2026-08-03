#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/convert-date-to-binary.h"

namespace leetcode {
namespace problem_3280 {

class ConvertDateToBinaryTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  ConvertDateToBinarySolution solution_;
};

TEST_P(ConvertDateToBinaryTest, Examples) {
  EXPECT_EQ("100000100000-10-11101", solution_.convertDateToBinary("2080-02-29"));
  EXPECT_EQ("11101101100-1-1", solution_.convertDateToBinary("1900-01-01"));
}

TEST_P(ConvertDateToBinaryTest, SelfAuthored) {
  EXPECT_EQ("10-1-1", solution_.convertDateToBinary("0002-01-01"));
  EXPECT_EQ("1-1010-11001", solution_.convertDateToBinary("0001-10-25"));
}

INSTANTIATE_TEST_SUITE_P(
    ConvertDateToBinaryTests, ConvertDateToBinaryTest,
    ::testing::ValuesIn(ConvertDateToBinarySolution().getStrategyNames()));

}  // namespace problem_3280
}  // namespace leetcode
