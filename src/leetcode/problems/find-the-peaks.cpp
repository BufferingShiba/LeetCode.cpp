#include "leetcode/problems/find-the-peaks.h"

namespace leetcode::problem_2951 {

namespace {

std::vector<int> findPeaksImpl(std::vector<int>& mountain) {
  std::vector<int> result;
  const int n = static_cast<int>(mountain.size());
  for (int i = 1; i + 1 < n; ++i) {
    if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
      result.push_back(i);
    }
  }
  return result;
}

}  // namespace

FindThePeaksSolution::FindThePeaksSolution() {
  setMetaInfo({.id = 2951,
               .title = "Find the Peaks",
               .url = "https://leetcode.com/problems/find-the-peaks/"});

  registerStrategy({.name = "SinglePassEnumeration",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "Enumeration"}},
                   findPeaksImpl);
}

std::vector<int> FindThePeaksSolution::findPeaks(std::vector<int>& mountain) {
  return getSolution()(mountain);
}

}  // namespace leetcode::problem_2951
