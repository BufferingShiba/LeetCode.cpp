#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/count-submatrices-with-all-ones.h"

namespace leetcode {
namespace problem_1504 {
namespace {

struct TestCase {
  std::vector<std::vector<int>> mat;
  int expected;
};

}  // namespace

class CountSubmatricesWithAllOnesTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  CountSubmatricesWithAllOnesSolution solution_;
};

TEST_P(CountSubmatricesWithAllOnesTest, Examples) {
  const std::vector<TestCase> cases = {
      {{{1, 0, 1}, {1, 1, 0}, {1, 1, 0}}, 13},
      {{{0, 1, 1, 0}, {0, 1, 1, 1}, {1, 1, 1, 0}}, 24},
  };

  for (const auto& tc : cases) {
    std::vector<std::vector<int>> mat = tc.mat;
    EXPECT_EQ(solution_.numSubmat(mat), tc.expected);
  }
}

TEST_P(CountSubmatricesWithAllOnesTest, SingleElement) {
  std::vector<std::vector<int>> mat = {{1}};
  EXPECT_EQ(solution_.numSubmat(mat), 1);
}

TEST_P(CountSubmatricesWithAllOnesTest, SelfAuthoredAllZeros) {
  std::vector<std::vector<int>> mat = {{0, 0, 0}, {0, 0, 0}};
  EXPECT_EQ(solution_.numSubmat(mat), 0);
}

TEST_P(CountSubmatricesWithAllOnesTest, SelfAuthoredAllOnes2x2) {
  std::vector<std::vector<int>> mat = {{1, 1}, {1, 1}};
  // 1x1: 4, 1x2: 2, 2x1: 2, 2x2: 1 => 9
  EXPECT_EQ(solution_.numSubmat(mat), 9);
}

INSTANTIATE_TEST_SUITE_P(
    CountSubmatricesWithAllOnesTestSuite, CountSubmatricesWithAllOnesTest,
    ::testing::ValuesIn(CountSubmatricesWithAllOnesSolution().getStrategyNames()));

}  // namespace problem_1504
}  // namespace leetcode
