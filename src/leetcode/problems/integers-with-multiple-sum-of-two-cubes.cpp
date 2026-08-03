#include "leetcode/problems/integers-with-multiple-sum-of-two-cubes.h"

#include <algorithm>
#include <unordered_map>

namespace leetcode {
namespace problem_3890 {

static vector<int> solution1(int n) {
  // Enumerate all distinct positive pairs (a, b) with a <= b such that
  // a^3 + b^3 <= n, and count how many different pairs yield each sum.
  std::unordered_map<long long, int> counts;
  for (long long a = 1; a * a * a <= n; ++a) {
    long long a3 = a * a * a;
    for (long long b = a; a3 + b * b * b <= n; ++b) {
      long long s = a3 + b * b * b;
      ++counts[s];
    }
  }

  // A good integer is one that arises from at least two distinct pairs.
  std::vector<int> result;
  for (const auto& entry : counts) {
    if (entry.second >= 2) {
      result.push_back(static_cast<int>(entry.first));
    }
  }
  std::sort(result.begin(), result.end());
  return result;
}

IntegersWithMultipleSumOfTwoCubesSolution::IntegersWithMultipleSumOfTwoCubesSolution() {
  setMetaInfo({
      .id = 3890,
      .title = "Integers With Multiple Sum of Two Cubes",
      .url = "https://leetcode.com/problems/integers-with-multiple-sum-of-two-cubes"
  });
  registerStrategy({.name = "Brute Force"}, solution1);
}

vector<int> IntegersWithMultipleSumOfTwoCubesSolution::findGoodIntegers(int n) {
  return getSolution()(n);
}

}  // namespace problem_3890
}  // namespace leetcode
