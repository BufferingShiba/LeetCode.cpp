#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/crawler-log-folder.h"

namespace leetcode {
namespace problem_1598 {
namespace {

class CrawlerLogFolderTest : public ::testing::TestWithParam<std::string> {
 protected:
  CrawlerLogFolderSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(CrawlerLogFolderTest, Example1) {
  std::vector<std::string> logs = {"d1/", "d2/", "../", "d21/", "./"};
  EXPECT_EQ(solution.minOperations(logs), 2);
}

TEST_P(CrawlerLogFolderTest, Example2) {
  std::vector<std::string> logs = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
  EXPECT_EQ(solution.minOperations(logs), 3);
}

TEST_P(CrawlerLogFolderTest, Example3) {
  std::vector<std::string> logs = {"d1/", "../", "../", "../"};
  EXPECT_EQ(solution.minOperations(logs), 0);
}

TEST_P(CrawlerLogFolderTest, SelfAuthoredStaysAtRootWithParentOps) {
  std::vector<std::string> logs = {"../", "../", "./"};
  EXPECT_EQ(solution.minOperations(logs), 0);
}

TEST_P(CrawlerLogFolderTest, SelfAuthoredSingleChild) {
  std::vector<std::string> logs = {"a/"};
  EXPECT_EQ(solution.minOperations(logs), 1);
}

INSTANTIATE_TEST_SUITE_P(
    CrawlerLogFolderTestSuite, CrawlerLogFolderTest,
    ::testing::ValuesIn(CrawlerLogFolderSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_1598
}  // namespace leetcode
