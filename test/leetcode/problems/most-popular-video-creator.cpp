#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/most-popular-video-creator.h"

namespace leetcode {
namespace problem_2456 {
namespace {

class MostPopularVideoCreatorTest : public ::testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution_.setStrategy(GetParam()); }

  MostPopularVideoCreatorSolution solution_;
};

std::vector<std::vector<std::string>> Canonicalize(
    const std::vector<std::vector<std::string>>& input) {
  std::vector<std::vector<std::string>> out = input;
  std::sort(out.begin(), out.end());
  return out;
}

TEST_P(MostPopularVideoCreatorTest, Example1) {
  std::vector<std::string> creators = {"alice", "bob", "alice", "chris"};
  std::vector<std::string> ids = {"one", "two", "three", "four"};
  std::vector<int> views = {5, 10, 5, 4};

  auto result = solution_.mostPopularCreator(creators, ids, views);

  std::vector<std::vector<std::string>> expected = {{"alice", "one"}, {"bob", "two"}};
  EXPECT_EQ(Canonicalize(result), Canonicalize(expected));
}

TEST_P(MostPopularVideoCreatorTest, Example2) {
  std::vector<std::string> creators = {"alice", "alice", "alice"};
  std::vector<std::string> ids = {"a", "b", "c"};
  std::vector<int> views = {1, 2, 2};

  auto result = solution_.mostPopularCreator(creators, ids, views);

  std::vector<std::vector<std::string>> expected = {{"alice", "b"}};
  EXPECT_EQ(Canonicalize(result), Canonicalize(expected));
}

TEST_P(MostPopularVideoCreatorTest, SelfAuthoredSingleCreatorSingleVideo) {
  std::vector<std::string> creators = {"x"};
  std::vector<std::string> ids = {"v1"};
  std::vector<int> views = {7};

  auto result = solution_.mostPopularCreator(creators, ids, views);

  std::vector<std::vector<std::string>> expected = {{"x", "v1"}};
  EXPECT_EQ(Canonicalize(result), Canonicalize(expected));
}

TEST_P(MostPopularVideoCreatorTest, SelfAuthoredLexSmallestIdOnTie) {
  std::vector<std::string> creators = {"c", "c"};
  std::vector<std::string> ids = {"z", "a"};
  std::vector<int> views = {5, 5};

  auto result = solution_.mostPopularCreator(creators, ids, views);

  std::vector<std::vector<std::string>> expected = {{"c", "a"}};
  EXPECT_EQ(Canonicalize(result), Canonicalize(expected));
}

INSTANTIATE_TEST_SUITE_P(
    MostPopularVideoCreatorTestSuite, MostPopularVideoCreatorTest,
    ::testing::ValuesIn(MostPopularVideoCreatorSolution().getStrategyNames()));

}  // namespace
}  // namespace problem_2456
}  // namespace leetcode
