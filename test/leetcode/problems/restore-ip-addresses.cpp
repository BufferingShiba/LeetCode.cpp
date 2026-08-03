#include "leetcode/problems/restore-ip-addresses.h"

#include "gtest/gtest.h"

namespace leetcode {
namespace problem_93 {

class RestoreIpAddressesTest : public ::testing::TestWithParam<string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }

  RestoreIpAddressesSolution solution;
};

// ===== Official Example 1 (from LeetCode) =====
// Input:  s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
TEST_P(RestoreIpAddressesTest, OfficialExample1) {
  const std::vector<std::string> expected = {"255.255.11.135", "255.255.111.35"};
  EXPECT_EQ(expected, solution.restoreIpAddresses("25525511135"));
}

// ===== Official Example 2 (from LeetCode) =====
// Input:  s = "0000"
// Output: ["0.0.0.0"]
TEST_P(RestoreIpAddressesTest, OfficialExample2) {
  const std::vector<std::string> expected = {"0.0.0.0"};
  EXPECT_EQ(expected, solution.restoreIpAddresses("0000"));
}

// ===== Official Example 3 (from LeetCode) =====
// Input:  s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
TEST_P(RestoreIpAddressesTest, OfficialExample3) {
  const std::vector<std::string> expected = {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"};
  EXPECT_EQ(expected, solution.restoreIpAddresses("101023"));
}


INSTANTIATE_TEST_SUITE_P(
    LeetCode, RestoreIpAddressesTest,
    ::testing::ValuesIn(RestoreIpAddressesSolution().getStrategyNames()));

}  // namespace problem_93
}  // namespace leetcode
