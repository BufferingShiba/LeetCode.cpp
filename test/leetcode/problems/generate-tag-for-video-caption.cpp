#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/generate-tag-for-video-caption.h"

namespace leetcode {
namespace problem_3582 {

class GenerateTagForVideoCaptionTest
    : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  GenerateTagForVideoCaptionSolution solution;
};

TEST_P(GenerateTagForVideoCaptionTest, Example1) {
  std::string caption = "Leetcode daily streak achieved";
  std::string expected = "#leetcodeDailyStreakAchieved";
  EXPECT_EQ(solution.generateTag(caption), expected);
}

TEST_P(GenerateTagForVideoCaptionTest, Example2) {
  std::string caption = "can I Go There";
  std::string expected = "#canIGoThere";
  EXPECT_EQ(solution.generateTag(caption), expected);
}

TEST_P(GenerateTagForVideoCaptionTest, Example3) {
  std::string caption =
      "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";
  std::string expected =
      "#hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";
  EXPECT_EQ(solution.generateTag(caption), expected);
}

INSTANTIATE_TEST_SUITE_P(
    GenerateTagForVideoCaptionGroup, GenerateTagForVideoCaptionTest,
    ::testing::ValuesIn(
        GenerateTagForVideoCaptionSolution().getStrategyNames()));

}  // namespace problem_3582
}  // namespace leetcode
