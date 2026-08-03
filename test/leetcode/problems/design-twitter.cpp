#include <gtest/gtest.h>

#include <vector>

#include "leetcode/problems/design-twitter.h"

namespace leetcode::problem_355 {

class DesignTwitterTest : public ::testing::TestWithParam<int> {
 protected:
  DesignTwitterSolution twitter_;
};

TEST_P(DesignTwitterTest, Example1) {
  // twitter.postTweet(1, 5);
  twitter_.postTweet(1, 5);
  // twitter.getNewsFeed(1) -> [5]
  EXPECT_EQ(twitter_.getNewsFeed(1), std::vector<int>{5});
  // twitter.follow(1, 2);
  twitter_.follow(1, 2);
  // twitter.postTweet(2, 6);
  twitter_.postTweet(2, 6);
  // twitter.getNewsFeed(1) -> [6, 5]
  EXPECT_EQ(twitter_.getNewsFeed(1), (std::vector<int>{6, 5}));
  // twitter.unfollow(1, 2);
  twitter_.unfollow(1, 2);
  // twitter.getNewsFeed(1) -> [5]
  EXPECT_EQ(twitter_.getNewsFeed(1), std::vector<int>{5});
}

INSTANTIATE_TEST_SUITE_P(DesignTwitter, DesignTwitterTest,
                         ::testing::Values(0));

}  // namespace leetcode::problem_355
