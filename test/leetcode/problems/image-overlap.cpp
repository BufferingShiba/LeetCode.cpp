#include <gtest/gtest.h>

#include "leetcode/problems/image-overlap.h"

namespace leetcode::problem_835 {

class ImageOverlapTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override {
    solution_.setStrategy(GetParam());
  }

  ImageOverlapSolution solution_;
};

TEST_P(ImageOverlapTest, Example1) {
  std::vector<std::vector<int>> img1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 0}};
  std::vector<std::vector<int>> img2 = {{0, 0, 0}, {0, 1, 1}, {0, 0, 1}};
  EXPECT_EQ(3, solution_.largestOverlap(img1, img2));
}

TEST_P(ImageOverlapTest, Example2) {
  std::vector<std::vector<int>> img1 = {{1}};
  std::vector<std::vector<int>> img2 = {{1}};
  EXPECT_EQ(1, solution_.largestOverlap(img1, img2));
}

TEST_P(ImageOverlapTest, Example3) {
  std::vector<std::vector<int>> img1 = {{0}};
  std::vector<std::vector<int>> img2 = {{0}};
  EXPECT_EQ(0, solution_.largestOverlap(img1, img2));
}

TEST_P(ImageOverlapTest, SelfAuthoredNoOverlapShifted) {
  std::vector<std::vector<int>> img1 = {{0, 1}, {0, 0}};
  std::vector<std::vector<int>> img2 = {{0, 0}, {1, 0}};
  // 左下角的 1 平移后可以覆盖 img2 的左上角：无需平移且无重叠？
  // img1 at (0,1), img2 at (1,0): dr=1-0=1, dc=0-1=-1 平移后 (1+...
  // 实际上两个 ones 位置可以通过平移重合，答案为 1。
  EXPECT_EQ(1, solution_.largestOverlap(img1, img2));
}

TEST_P(ImageOverlapTest, SelfAuthoredAllOnes) {
  std::vector<std::vector<int>> img1 = {{1, 1}, {1, 1}};
  std::vector<std::vector<int>> img2 = {{1, 1}, {1, 1}};
  // 可以完全重合（零平移），4 个位置同时为 1。
  EXPECT_EQ(4, solution_.largestOverlap(img1, img2));
}

INSTANTIATE_TEST_SUITE_P(
    ImageOverlapTestSuite, ImageOverlapTest,
    ::testing::ValuesIn(ImageOverlapSolution().getStrategyNames()));

}  // namespace leetcode::problem_835
