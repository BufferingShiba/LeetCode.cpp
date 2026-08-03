#include <gtest/gtest.h>

#include "leetcode/problems/properties-graph.h"
#include <vector>

namespace leetcode {
namespace problem_3493 {
namespace {

class PropertiesGraphTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  PropertiesGraphSolution solution_;
};

TEST_P(PropertiesGraphTest, Example1) {
  std::vector<std::vector<int>> properties = {
      {1, 2}, {1, 1}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
  int k = 1;
  EXPECT_EQ(3, solution_.numberOfComponents(properties, k));
}

TEST_P(PropertiesGraphTest, Example2) {
  std::vector<std::vector<int>> properties = {{1, 2, 3}, {2, 3, 4}, {4, 3, 5}};
  int k = 2;
  EXPECT_EQ(1, solution_.numberOfComponents(properties, k));
}

TEST_P(PropertiesGraphTest, Example3) {
  std::vector<std::vector<int>> properties = {{1, 1}, {1, 1}};
  int k = 2;
  EXPECT_EQ(2, solution_.numberOfComponents(properties, k));
}

INSTANTIATE_TEST_SUITE_P(
    Strategies,
    PropertiesGraphTest,
    testing::ValuesIn(PropertiesGraphSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_3493
}  // namespace leetcode
