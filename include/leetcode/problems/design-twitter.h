#ifndef LEETCODE_PROBLEMS_DESIGN_TWITTER_H_
#define LEETCODE_PROBLEMS_DESIGN_TWITTER_H_

#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace leetcode::problem_355 {

class Twitter {
 public:
  Twitter();

  void postTweet(int userId, int tweetId);

  std::vector<int> getNewsFeed(int userId);

  void follow(int followerId, int followeeId);

  void unfollow(int followerId, int followeeId);

 private:
  int global_timestamp_;
  // userId -> list of (timestamp, tweetId), ordered from old to new
  std::unordered_map<int, std::vector<std::pair<int, int>>> tweets_;
  // followerId -> set of followeeIds
  std::unordered_map<int, std::unordered_set<int>> follows_;
};

// Alias for test compatibility
using DesignTwitterSolution = Twitter;

}  // namespace leetcode::problem_355

#endif  // LEETCODE_PROBLEMS_DESIGN_TWITTER_H_
