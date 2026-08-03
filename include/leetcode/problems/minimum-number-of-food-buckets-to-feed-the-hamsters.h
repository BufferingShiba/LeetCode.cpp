#include "leetcode/core.h"

namespace leetcode {
namespace problem_2086 {

using Func = std::function<int(string)>;

class MinimumNumberOfFoodBucketsToFeedTheHamstersSolution : public SolutionBase<Func> {
 public:
  //! 2086. Minimum Number of Food Buckets to Feed the Hamsters
  //! https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/
  int minimumBuckets(string hamsters);

  MinimumNumberOfFoodBucketsToFeedTheHamstersSolution();
};

}  // namespace problem_2086
}  // namespace leetcode
