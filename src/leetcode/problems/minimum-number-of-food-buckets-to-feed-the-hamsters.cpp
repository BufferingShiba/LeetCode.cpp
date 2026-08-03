#include "leetcode/problems/minimum-number-of-food-buckets-to-feed-the-hamsters.h"

#include <vector>

namespace leetcode {
namespace problem_2086 {

static int solution1(string hamsters) {
  const int n = static_cast<int>(hamsters.size());
  std::vector<bool> fed(n, false);
  int buckets = 0;
  for (int i = 0; i < n; ++i) {
    if (hamsters[i] == '.' || fed[i]) continue;
    // Prefer placing the bucket at i+1: it can also feed hamster at i+2.
    if (i + 1 < n && hamsters[i + 1] == '.') {
      ++buckets;
      fed[i] = true;
      if (i + 2 < n && hamsters[i + 2] == 'H') fed[i + 2] = true;
    } else if (i - 1 >= 0 && hamsters[i - 1] == '.') {
      ++buckets;
      fed[i] = true;
    } else {
      return -1;
    }
  }
  return buckets;
}

MinimumNumberOfFoodBucketsToFeedTheHamstersSolution::MinimumNumberOfFoodBucketsToFeedTheHamstersSolution() {
  setMetaInfo({
      .id = 2086,
      .title = "Minimum Number of Food Buckets to Feed the Hamsters",
      .url = "https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters"
  });
  registerStrategy({.name = "Greedy", .time_complexity = "O(n)", .space_complexity = "O(n)", .tags = {"String", "Greedy"}}, solution1);
}

int MinimumNumberOfFoodBucketsToFeedTheHamstersSolution::minimumBuckets(string hamsters) {
  return getSolution()(hamsters);
}

}  // namespace problem_2086
}  // namespace leetcode
