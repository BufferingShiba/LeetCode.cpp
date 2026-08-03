#ifndef LEETCODE_PROBLEM_1348_TWEET_COUNTS_PER_FREQUENCY_H_
#define LEETCODE_PROBLEM_1348_TWEET_COUNTS_PER_FREQUENCY_H_

#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode {
namespace problem_1348 {

class TweetCounts {
 public:
  TweetCounts();

  void recordTweet(std::string tweetName, int time);

  std::vector<int> getTweetCountsPerFrequency(std::string freq,
                                               std::string tweetName,
                                               int startTime,
                                               int endTime);

 private:
  std::unordered_map<std::string, std::vector<int>> tweets_;
  std::unordered_map<std::string, bool> sorted_;
};

}  // namespace problem_1348
}  // namespace leetcode

#endif  // LEETCODE_PROBLEM_1348_TWEET_COUNTS_PER_FREQUENCY_H_
