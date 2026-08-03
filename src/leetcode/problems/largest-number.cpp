#include "leetcode/problems/largest-number.h"

#include <algorithm>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_179 {

// Sort by string concatenation: x should precede y iff x+y > y+x.
// This gives the lexicographically largest arrangement, which is the
// maximum number when concatenated.
static string solution1(vector<int>& nums) {
  vector<string> strs;
  strs.reserve(nums.size());
  for (int n : nums) {
    strs.push_back(std::to_string(n));
  }

  std::sort(strs.begin(), strs.end(),
            [](const string& a, const string& b) {
              return a + b > b + a;
            });

  // If the largest element is "0", the whole result is "0".
  if (strs[0] == "0") {
    return "0";
  }

  string result;
  for (const string& s : strs) {
    result += s;
  }
  return result;
}

LargestNumberSolution::LargestNumberSolution() {
  setMetaInfo({
      .id = 179,
      .title = "Largest Number",
      .url = "https://leetcode.com/problems/largest-number"
  });
  registerStrategy(
      {.name = "Sort by Concatenation",
       .expected = "Accepted",
       .time_complexity = "O(n log n * L)",
       .space_complexity = "O(n * L)",
       .tags = {"Sort", "String", "Greedy"}},
      solution1);
}

string LargestNumberSolution::largestNumber(vector<int>& nums) {
  return getSolution()(nums);
}

}  // namespace problem_179
}  // namespace leetcode
