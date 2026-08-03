#include "leetcode/problems/maximum-repeating-substring.h"

#include <string>

namespace leetcode {
namespace problem_1668 {

namespace {

int maxRepeatingImpl(std::string sequence, std::string word) {
  int k = 0;
  std::string repeated = word;
  while (sequence.find(repeated) != std::string::npos) {
    ++k;
    repeated += word;
  }
  return k;
}

}  // namespace

MaximumRepeatingSubstringSolution::MaximumRepeatingSubstringSolution() {
  setMetaInfo({.id = 1668,
               .title = "Maximum Repeating Substring",
               .url = "https://leetcode.com/problems/maximum-repeating-substring/"});
  registerStrategy({.name = "IncrementalRepeating",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2)",
                    .space_complexity = "O(n)",
                    .tags = {"String", "Dynamic Programming"}},
                   maxRepeatingImpl);
}

int MaximumRepeatingSubstringSolution::maxRepeating(std::string sequence,
                                                    std::string word) {
  return getSolution()(std::move(sequence), std::move(word));
}

}  // namespace problem_1668
}  // namespace leetcode
