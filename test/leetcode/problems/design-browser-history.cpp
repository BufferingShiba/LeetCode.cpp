#include <gtest/gtest.h>

#include "leetcode/problems/design-browser-history.h"

namespace leetcode {
namespace problem_1472 {

class DesignBrowserHistoryTest : public ::testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(DesignBrowserHistoryTest, Example1) {
  BrowserHistory browser("leetcode.com");
  browser.visit("google.com");
  browser.visit("facebook.com");
  browser.visit("youtube.com");

  EXPECT_EQ(browser.back(1), "facebook.com");
  EXPECT_EQ(browser.back(1), "google.com");
  EXPECT_EQ(browser.forward(1), "facebook.com");

  browser.visit("linkedin.com");

  EXPECT_EQ(browser.forward(2), "linkedin.com");
  EXPECT_EQ(browser.back(2), "google.com");
  EXPECT_EQ(browser.back(7), "leetcode.com");
}

INSTANTIATE_TEST_SUITE_P(, DesignBrowserHistoryTest, ::testing::Values(0));

}  // namespace problem_1472
}  // namespace leetcode
