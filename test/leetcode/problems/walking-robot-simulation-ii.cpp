#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/walking-robot-simulation-ii.h"

namespace leetcode {
namespace problem_2069 {

namespace {

std::vector<std::string> RunCommands(
    const std::vector<std::string>& commands,
    const std::vector<std::vector<int>>& args) {
  return walkingRobotSimulationIiSolution(commands, args);
}

}  // namespace

class WalkingRobotSimulationIiTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  WalkingRobotSimulationIiSolution solution_;
};

TEST_P(WalkingRobotSimulationIiTest, OfficialExample1) {
  const std::vector<std::string> commands = {
      "Robot", "step", "step", "getPos", "getDir", "step", "step", "step", "getPos", "getDir"};
  const std::vector<std::vector<int>> args = {
      {6, 3}, {2}, {2}, {}, {}, {2}, {1}, {4}, {}, {}};
  const std::vector<std::string> expected = {
      "null", "null", "null", "[4,0]", "East", "null", "null", "null", "[1,2]", "West"};
  EXPECT_EQ(RunCommands(commands, args), expected);
}

TEST_P(WalkingRobotSimulationIiTest, CornerTurnAtBottomLeft) {
  // Perimeter = 2*(4-1)+2*(4-1) = 12 for a 4x4 grid.
  // step 11 lands at (0,1) facing South; step 1 reaches (0,0) facing South;
  // next step at the corner turns East and moves one cell forward to (1,0).
  const std::vector<std::string> commands = {
      "Robot", "step", "getPos", "getDir", "step", "getPos", "getDir", "step", "getPos", "getDir"};
  const std::vector<std::vector<int>> args = {
      {4, 4}, {11}, {}, {}, {1}, {}, {}, {1}, {}, {}};
  const std::vector<std::string> expected = {
      "null", "null", "[0,1]", "South", "null", "[0,0]", "South", "null", "[1,0]", "East"};
  EXPECT_EQ(RunCommands(commands, args), expected);
}

TEST_P(WalkingRobotSimulationIiTest, InitialStateAndLargeStep) {
  // 2x2 grid, perimeter = 4. 100000 % 4 == 0, returns to origin facing South.
  const std::vector<std::string> commands = {
      "Robot", "getPos", "getDir", "step", "getPos", "getDir"};
  const std::vector<std::vector<int>> args = {
      {2, 2}, {}, {}, {100000}, {}, {}};
  const std::vector<std::string> expected = {
      "null", "[0,0]", "East", "null", "[0,0]", "South"};
  EXPECT_EQ(RunCommands(commands, args), expected);
}

TEST_P(WalkingRobotSimulationIiTest, StepExactlyPerimeterFromStart) {
  // 3x5 grid, perimeter = 2*2 + 2*4 = 12.
  const std::vector<std::string> commands = {
      "Robot", "step", "getPos", "getDir", "step", "getPos", "getDir"};
  const std::vector<std::vector<int>> args = {
      {3, 5}, {12}, {}, {}, {1}, {}, {}};
  const std::vector<std::string> expected = {
      "null", "null", "[0,0]", "South", "null", "[1,0]", "East"};
  EXPECT_EQ(RunCommands(commands, args), expected);
}

INSTANTIATE_TEST_SUITE_P(
    WalkingRobotSimulationIiTestInstantiation, WalkingRobotSimulationIiTest,
    ::testing::ValuesIn(WalkingRobotSimulationIiSolution().getStrategyNames()));

}  // namespace problem_2069
}  // namespace leetcode
