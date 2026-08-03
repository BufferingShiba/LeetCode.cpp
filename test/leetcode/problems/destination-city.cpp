#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/destination-city.h"

namespace leetcode {
namespace problem_1436 {

class DestinationCityTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  DestinationCitySolution solution;
};

TEST_P(DestinationCityTest, Example1) {
  std::vector<std::vector<std::string>> paths = {
      {"London", "New York"}, {"New York", "Lima"}, {"Lima", "Sao Paulo"}};
  EXPECT_EQ(solution.destCity(paths), "Sao Paulo");
}

TEST_P(DestinationCityTest, Example2) {
  std::vector<std::vector<std::string>> paths = {
      {"B", "C"}, {"D", "B"}, {"C", "A"}};
  EXPECT_EQ(solution.destCity(paths), "A");
}

TEST_P(DestinationCityTest, Example3) {
  std::vector<std::vector<std::string>> paths = {{"A", "Z"}};
  EXPECT_EQ(solution.destCity(paths), "Z");
}

INSTANTIATE_TEST_SUITE_P(, DestinationCityTest,
                         ::testing::ValuesIn(
                             DestinationCitySolution().getStrategyNames()));

}  // namespace problem_1436
}  // namespace leetcode
