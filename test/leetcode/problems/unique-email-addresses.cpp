#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "leetcode/problems/unique-email-addresses.h"

namespace leetcode {
namespace problem_929 {

class UniqueEmailAddressesTest : public ::testing::TestWithParam<std::string> {
 protected:
  UniqueEmailAddressesSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }
};

TEST_P(UniqueEmailAddressesTest, Example1) {
  std::vector<std::string> emails = {"test.email+alex@leetcode.com",
                                     "test.e.mail+bob.cathy@leetcode.com",
                                     "testemail+david@lee.tcode.com"};
  EXPECT_EQ(solution.numUniqueEmails(emails), 2);
}

TEST_P(UniqueEmailAddressesTest, Example2) {
  std::vector<std::string> emails = {"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"};
  EXPECT_EQ(solution.numUniqueEmails(emails), 3);
}

TEST_P(UniqueEmailAddressesTest, SelfAuthoredDotAndPlusInLocal) {
  std::vector<std::string> emails = {"m.y+name@email.com", "my@email.com", "my+alias+extra@email.com"};
  EXPECT_EQ(solution.numUniqueEmails(emails), 1);
}

INSTANTIATE_TEST_SUITE_P(UniqueEmailAddressesTestCases, UniqueEmailAddressesTest,
                         ::testing::ValuesIn(UniqueEmailAddressesSolution().getStrategyNames()));

}  // namespace problem_929
}  // namespace leetcode
