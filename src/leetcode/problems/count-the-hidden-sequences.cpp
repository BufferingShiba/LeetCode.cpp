#include "leetcode/problems/count-the-hidden-sequences.h"

#include <algorithm>

namespace leetcode {
namespace problem_2145 {

static int solution1(vector<int>& differences, int lower, int upper) {
  long long prefix = 0;
  long long minPrefix = 0;
  long long maxPrefix = 0;
  for (int d : differences) {
    prefix += d;
    minPrefix = std::min(minPrefix, prefix);
    maxPrefix = std::max(maxPrefix, prefix);
  }

  // hidden[0] must satisfy: lower - minPrefix <= hidden[0] <= upper - maxPrefix
  long long lo = static_cast<long long>(lower) - minPrefix;
  long long hi = static_cast<long long>(upper) - maxPrefix;
  if (hi < lo) {
    return 0;
  }
  return static_cast<int>(hi - lo + 1);
}

CountTheHiddenSequencesSolution::CountTheHiddenSequencesSolution() {
  setMetaInfo({
      .id = 2145,
      .title = "Count the Hidden Sequences",
      .url = "https://leetcode.com/problems/count-the-hidden-sequences"
  });
  registerStrategy({.name = "Prefix Min/Max", .expected = "Accepted",
                    .time_complexity = "O(n)", .space_complexity = "O(1)",
                    .tags = {"Array", "Prefix Sum"}},
                   solution1);
}

int CountTheHiddenSequencesSolution::numberOfArrays(vector<int>& differences, int lower, int upper) {
  return getSolution()(differences, lower, upper);
}

}  // namespace problem_2145
}  // namespace leetcode
