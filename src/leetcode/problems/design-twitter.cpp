#include "leetcode/problems/design-twitter.h"

#include <queue>

namespace leetcode::problem_355 {

Twitter::Twitter() : global_timestamp_(0) {}

void Twitter::postTweet(int userId, int tweetId) {
  tweets_[userId].emplace_back(global_timestamp_++, tweetId);
}

std::vector<int> Twitter::getNewsFeed(int userId) {
  // Collect unique users: self + followees
  std::unordered_set<int> users;
  users.insert(userId);
  auto fit = follows_.find(userId);
  if (fit != follows_.end()) {
    for (int followeeId : fit->second) {
      users.insert(followeeId);
    }
  }

  // Build references to non-empty tweet lists
  struct UserListRef {
    int userId;
    std::vector<std::pair<int, int>>* tweets;
  };
  std::vector<UserListRef> lists;
  for (int uid : users) {
    auto tit = tweets_.find(uid);
    if (tit != tweets_.end() && !tit->second.empty()) {
      lists.push_back({uid, &tit->second});
    }
  }

  // K-way merge with max-heap (most recent first)
  struct HeapItem {
    int timestamp;
    int tweetId;
    int listIndex;  // index into lists
    int pos;        // position in the tweet list (from the end)

    bool operator<(const HeapItem& other) const {
      // max-heap: larger timestamp has higher priority
      return timestamp < other.timestamp;
    }
  };

  std::priority_queue<HeapItem> pq;
  for (int i = 0; i < static_cast<int>(lists.size()); ++i) {
    auto& vec = *lists[i].tweets;
    int last = static_cast<int>(vec.size()) - 1;
    pq.push({vec[last].first, vec[last].second, i, last});
  }

  std::vector<int> result;
  result.reserve(10);
  for (int i = 0; i < 10 && !pq.empty(); ++i) {
    HeapItem top = pq.top();
    pq.pop();
    result.push_back(top.tweetId);

    if (top.pos > 0) {
      int newPos = top.pos - 1;
      auto& vec = *lists[top.listIndex].tweets;
      pq.push({vec[newPos].first, vec[newPos].second, top.listIndex, newPos});
    }
  }

  return result;
}

void Twitter::follow(int followerId, int followeeId) {
  follows_[followerId].insert(followeeId);
}

void Twitter::unfollow(int followerId, int followeeId) {
  auto it = follows_.find(followerId);
  if (it != follows_.end()) {
    it->second.erase(followeeId);
  }
}

}  // namespace leetcode::problem_355
