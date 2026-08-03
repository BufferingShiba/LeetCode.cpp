#include <gtest/gtest.h>

#include <string>
#include <unordered_map>

#include "leetcode/problems/generate-a-string-with-characters-that-have-odd-counts.h"

namespace leetcode {
namespace problem_1374 {

class GenerateAStringWithCharactersThatHaveOddCountsTest
    : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  GenerateAStringWithCharactersThatHaveOddCountsSolution solution;
};

// Helper: verify every char in s appears an odd number of times
static bool allCharsHaveOddCount(const std::string& s) {
  std::unordered_map<char, int> freq;
  for (char c : s) {
    ++freq[c];
  }
  for (const auto& [ch, cnt] : freq) {
    if (cnt % 2 == 0) return false;
  }
  return true;
}

TEST_P(GenerateAStringWithCharactersThatHaveOddCountsTest, Example1) {
  // n=4
  auto result = solution.generateTheString(4);
  EXPECT_EQ(result.size(), 4);
  EXPECT_TRUE(allCharsHaveOddCount(result));
}

TEST_P(GenerateAStringWithCharactersThatHaveOddCountsTest, Example2) {
  // n=2
  auto result = solution.generateTheString(2);
  EXPECT_EQ(result.size(), 2);
  EXPECT_TRUE(allCharsHaveOddCount(result));
}

TEST_P(GenerateAStringWithCharactersThatHaveOddCountsTest, Example3) {
  // n=7
  auto result = solution.generateTheString(7);
  EXPECT_EQ(result.size(), 7);
  EXPECT_TRUE(allCharsHaveOddCount(result));
}

TEST_P(GenerateAStringWithCharactersThatHaveOddCountsTest, SelfAuthored) {
  // n=1 (odd)
  auto r1 = solution.generateTheString(1);
  EXPECT_EQ(r1.size(), 1);
  EXPECT_TRUE(allCharsHaveOddCount(r1));

  // n=500 (even, max constraint)
  auto r2 = solution.generateTheString(500);
  EXPECT_EQ(r2.size(), 500);
  EXPECT_TRUE(allCharsHaveOddCount(r2));

  // n=3 (odd)
  auto r3 = solution.generateTheString(3);
  EXPECT_EQ(r3.size(), 3);
  EXPECT_TRUE(allCharsHaveOddCount(r3));
}

INSTANTIATE_TEST_SUITE_P(
    AllStrategies,
    GenerateAStringWithCharactersThatHaveOddCountsTest,
    testing::ValuesIn(
        GenerateAStringWithCharactersThatHaveOddCountsSolution()
            .getStrategyNames()));

}  // namespace problem_1374
}  // namespace leetcode
