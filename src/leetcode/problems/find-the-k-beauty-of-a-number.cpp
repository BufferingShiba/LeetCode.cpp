#include "leetcode/problems/find-the-k-beauty-of-a-number.h"

#include <string>

namespace leetcode {
namespace problem_2269 {
namespace {

int divisorSubstringsImpl(int num, int k) {
  std::string s = std::to_string(num);
  int n = static_cast<int>(s.size());
  int count = 0;
  for (int i = 0; i + k <= n; ++i) {
    long value = std::stol(s.substr(i, k));
    if (value != 0 && num % value == 0) {
      ++count;
    }
  }
  return count;
}

}  // namespace

FindTheKBeautyOfANumberSolution::FindTheKBeautyOfANumberSolution() {
  setMetaInfo({.id = 2269,
               .title = "Find the K-Beauty of a Number",
               .url = "https://leetcode.com/problems/find-the-k-beauty-of-a-number/"});
  registerStrategy({.name = "SlidingWindow",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"String", "Sliding Window"}},
                   divisorSubstringsImpl);
}

int FindTheKBeautyOfANumberSolution::divisorSubstrings(int num, int k) {
  return getSolution()(num, k);
}

}  // namespace problem_2269
}  // namespace leetcode
