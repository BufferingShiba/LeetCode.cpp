#include <gtest/gtest.h>
#include "leetcode/problems/watering-plants.h"

using namespace leetcode::problem_2079;

class WateringPlantsTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }
  WateringPlantsSolution solution_;
};

TEST_P(WateringPlantsTest, Example1) {
  std::vector<int> plants = {2, 2, 3, 3};
  int capacity = 5;
  EXPECT_EQ(solution_.wateringPlants(plants, capacity), 14);
}

TEST_P(WateringPlantsTest, Example2) {
  std::vector<int> plants = {1, 1, 1, 4, 2, 3};
  int capacity = 4;
  EXPECT_EQ(solution_.wateringPlants(plants, capacity), 30);
}

TEST_P(WateringPlantsTest, Example3) {
  std::vector<int> plants = {7, 7, 7, 7, 7, 7, 7};
  int capacity = 8;
  EXPECT_EQ(solution_.wateringPlants(plants, capacity), 49);
}

INSTANTIATE_TEST_SUITE_P(
    WateringPlants,
    WateringPlantsTest,
    testing::ValuesIn(WateringPlantsSolution().getStrategyNames()));
