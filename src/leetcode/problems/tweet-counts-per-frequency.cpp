#include "leetcode/problems/tweet-counts-per-frequency.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_1348 {

TweetCounts::TweetCounts() {}

void TweetCounts::recordTweet(std::string tweetName, int time) {
  tweets_[tweetName].push_back(time);
  sorted_[tweetName] = false;
}

std::vector<int> TweetCounts::getTweetCountsPerFrequency(
    std::string freq, std::string tweetName, int startTime, int endTime) {
  int chunkSize;
  if (freq == "minute") {
    chunkSize = 60;
  } else if (freq == "hour") {
    chunkSize = 3600;
  } else {
    chunkSize = 86400;  // "day"
  }

  int numChunks = (endTime - startTime) / chunkSize + 1;
  std::vector<int> result(numChunks, 0);

  auto it = tweets_.find(tweetName);
  if (it == tweets_.end()) {
    return result;
  }

  auto& times = it->second;
  if (!sorted_[tweetName]) {
    std::sort(times.begin(), times.end());
    sorted_[tweetName] = true;
  }

  auto left = std::lower_bound(times.begin(), times.end(), startTime);
  auto right = std::upper_bound(times.begin(), times.end(), endTime);

  for (auto iter = left; iter != right; ++iter) {
    int t = *iter;
    int chunkIdx = (t - startTime) / chunkSize;
    if (chunkIdx >= numChunks) {
      chunkIdx = numChunks - 1;
    }
    result[chunkIdx]++;
  }

  return result;
}

}  // namespace problem_1348
}  // namespace leetcode
