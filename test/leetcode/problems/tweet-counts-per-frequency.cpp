#include <gtest/gtest.h>

#include "leetcode/problems/tweet-counts-per-frequency.h"

using namespace leetcode::problem_1348;

class TweetCountsPerFrequencyTest : public testing::TestWithParam<int> {
 protected:
  void SetUp() override {}
};

TEST_P(TweetCountsPerFrequencyTest, OfficialExample) {
  TweetCounts tc;
  tc.recordTweet("tweet3", 0);
  tc.recordTweet("tweet3", 60);
  tc.recordTweet("tweet3", 10);

  auto res1 = tc.getTweetCountsPerFrequency("minute", "tweet3", 0, 59);
  EXPECT_EQ(res1, std::vector<int>({2}));

  auto res2 = tc.getTweetCountsPerFrequency("minute", "tweet3", 0, 60);
  EXPECT_EQ(res2, (std::vector<int>{2, 1}));

  tc.recordTweet("tweet3", 120);

  auto res3 = tc.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);
  EXPECT_EQ(res3, std::vector<int>({4}));
}

TEST_P(TweetCountsPerFrequencyTest, NonExistentTweet) {
  TweetCounts tc;
  auto res = tc.getTweetCountsPerFrequency("minute", "nonexistent", 0, 100);
  // (100-0)/60 + 1 = 2 chunks
  EXPECT_EQ(res, (std::vector<int>{0, 0}));
}

TEST_P(TweetCountsPerFrequencyTest, DayFrequency) {
  TweetCounts tc;
  tc.recordTweet("t", 0);
  tc.recordTweet("t", 86400);
  tc.recordTweet("t", 100000);

  // [0, 200000] with day chunks (86400s), numChunks = (200000-0)/86400 + 1 = 3
  // chunk 0: [0, 86399]     → time 0
  // chunk 1: [86400, 172799] → time 86400, time 100000
  // chunk 2: [172800, 200000] → (empty)
  auto res = tc.getTweetCountsPerFrequency("day", "t", 0, 200000);
  EXPECT_EQ(res.size(), 3u);
  EXPECT_EQ(res[0], 1);
  EXPECT_EQ(res[1], 2);
  EXPECT_EQ(res[2], 0);
}

TEST_P(TweetCountsPerFrequencyTest, SinglePointRange) {
  TweetCounts tc;
  tc.recordTweet("t", 42);
  tc.recordTweet("t", 42);

  auto res = tc.getTweetCountsPerFrequency("minute", "t", 42, 42);
  // (42-42)/60 + 1 = 1 chunk
  EXPECT_EQ(res, std::vector<int>({2}));
}

TEST_P(TweetCountsPerFrequencyTest, MultipleTweetNames) {
  TweetCounts tc;
  tc.recordTweet("a", 10);
  tc.recordTweet("b", 20);
  tc.recordTweet("a", 30);

  // [0, 60] minute → 2 chunks: [0,59], [60,60]
  auto resA = tc.getTweetCountsPerFrequency("minute", "a", 0, 60);
  EXPECT_EQ(resA, (std::vector<int>{2, 0}));

  auto resB = tc.getTweetCountsPerFrequency("minute", "b", 0, 60);
  EXPECT_EQ(resB, (std::vector<int>{1, 0}));
}

INSTANTIATE_TEST_SUITE_P(All, TweetCountsPerFrequencyTest, testing::Values(0));
