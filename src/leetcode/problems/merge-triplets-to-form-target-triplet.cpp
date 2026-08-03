#include "leetcode/problems/merge-triplets-to-form-target-triplet.h"

namespace leetcode {
namespace problem_1899 {

namespace {

bool mergeTripletsImpl(std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
  int ax = 0, ay = 0, az = 0;
  const int tx = target[0], ty = target[1], tz = target[2];
  for (const auto& t : triplets) {
    const int a = t[0], b = t[1], c = t[2];
    // Only feasible triplets (no dimension exceeding target) can contribute.
    if (a > tx || b > ty || c > tz) {
      continue;
    }
    ax = std::max(ax, a);
    ay = std::max(ay, b);
    az = std::max(az, c);
  }
  return ax == tx && ay == ty && az == tz;
}

}  // namespace

MergeTripletsToFormTargetTriplet::MergeTripletsToFormTargetTriplet() {
  setMetaInfo({.id = 1899,
               .title = "Merge Triplets to Form Target Triplet",
               .url = "https://leetcode.com/problems/merge-triplets-to-form-target-triplet/"});
  registerStrategy(
      {"GreedyScan", "Accepted", "O(n)", "O(1)", {"Array", "Greedy"},
       "Only keep triplets whose every dimension <= target, then accumulate per-dimension max."},
      mergeTripletsImpl);
}

bool MergeTripletsToFormTargetTriplet::mergeTriplets(std::vector<std::vector<int>>& triplets,
                                                     std::vector<int>& target) {
  return getSolution()(triplets, target);
}

}  // namespace problem_1899
}  // namespace leetcode
