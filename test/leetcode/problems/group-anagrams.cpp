#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "leetcode/problems/group-anagrams.h"

using namespace leetcode::problem_49;

class GroupAnagramsTest : public testing::TestWithParam<std::string> {
 protected:
  GroupAnagramsSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }

  // 辅助：对 actual 和 expected 都做组内排序 + 组间排序，消除顺序差异后比较
  void expectSameGroups(const std::vector<std::vector<std::string>>& actual,
                        const std::vector<std::vector<std::string>>& expected) {
    auto normalize = [](std::vector<std::vector<std::string>> groups) {
      for (auto& g : groups) {
        std::sort(g.begin(), g.end());
      }
      std::sort(groups.begin(), groups.end());
      return groups;
    };
    EXPECT_EQ(normalize(actual), normalize(expected));
  }
};

TEST_P(GroupAnagramsTest, Example1) {
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto result = solution.groupAnagrams(strs);
  std::vector<std::vector<std::string>> expected = {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
  expectSameGroups(result, expected);
}

TEST_P(GroupAnagramsTest, Example2) {
  std::vector<std::string> strs = {""};
  auto result = solution.groupAnagrams(strs);
  std::vector<std::vector<std::string>> expected = {{""}};
  expectSameGroups(result, expected);
}

TEST_P(GroupAnagramsTest, Example3) {
  std::vector<std::string> strs = {"a"};
  auto result = solution.groupAnagrams(strs);
  std::vector<std::vector<std::string>> expected = {{"a"}};
  expectSameGroups(result, expected);
}

INSTANTIATE_TEST_SUITE_P(Strategies, GroupAnagramsTest,
                         testing::ValuesIn(GroupAnagramsSolution().getStrategyNames()));
