#include <gtest/gtest.h>

#include <string>

#include "leetcode/problems/hexadecimal-and-hexatrigesimal-conversion.h"

namespace leetcode {
namespace problem_3602 {
namespace {

class HexadecimalAndHexatrigesimalConversionTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  HexadecimalAndHexatrigesimalConversionSolution solution_;
};

TEST_P(HexadecimalAndHexatrigesimalConversionTest, Example1) {
  EXPECT_EQ("A91P1", solution_.concatHex36(13));
}

TEST_P(HexadecimalAndHexatrigesimalConversionTest, Example2) {
  EXPECT_EQ("5101000", solution_.concatHex36(36));
}

TEST_P(HexadecimalAndHexatrigesimalConversionTest, SelfAuthoredNIsOne) {
  // n = 1: n^2 = 1 -> hex "1"; n^3 = 1 -> base36 "1"; result "11"
  EXPECT_EQ("11", solution_.concatHex36(1));
}

TEST_P(HexadecimalAndHexatrigesimalConversionTest, SelfAuthoredNIsTen) {
  // n = 10: n^2 = 100 -> hex "64"; n^3 = 1000 -> base36
  // 1000 = 27*36 + 28  (27 -> R, 28 -> S) => "RS"
  EXPECT_EQ("64RS", solution_.concatHex36(10));
}

INSTANTIATE_TEST_SUITE_P(
    HexadecimalAndHexatrigesimalConversionTestSuite,
    HexadecimalAndHexatrigesimalConversionTest,
    ::testing::ValuesIn(HexadecimalAndHexatrigesimalConversionSolution()
                            .getStrategyNames()));

}  // namespace
}  // namespace problem_3602
}  // namespace leetcode
