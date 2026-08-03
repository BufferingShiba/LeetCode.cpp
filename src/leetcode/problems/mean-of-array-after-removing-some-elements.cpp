#include "leetcode/problems/mean-of-array-after-removing-some-elements.h"

#include <algorithm>

namespace leetcode {
namespace problem_1619 {

namespace {

double trimMeanImpl(std::vector<int>& arr) {
  std::sort(arr.begin(), arr.end());
  int n = static_cast<int>(arr.size());
  int k = n / 20;  // 5% of elements on each side
  long long sum = 0;
  for (int i = k; i < n - k; ++i) {
    sum += arr[i];
  }
  return static_cast<double>(sum) / (n - 2 * k);
}

}  // namespace

MeanOfArrayAfterRemovingSomeElementsSolution::MeanOfArrayAfterRemovingSomeElementsSolution() {
  setMetaInfo({.id = 1619,
               .title = "Mean of Array After Removing Some Elements",
               .url = "https://leetcode.com/problems/mean-of-array-after-removing-some-elements/"});
  registerStrategy({.name = "SortAndTrim",
                    .expected = "Accepted",
                    .time_complexity = "O(n log n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Sorting"}},
                   trimMeanImpl);
}

}  // namespace problem_1619
}  // namespace leetcode
