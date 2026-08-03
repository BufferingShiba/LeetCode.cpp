#include "leetcode/problems/count-prefix-and-suffix-pairs-i.h"

namespace leetcode {
namespace problem_3042 {
namespace {

bool isPrefixAndSuffix(const std::string& str1, const std::string& str2) {
  if (str1.size() > str2.size()) {
    return false;
  }
  return str2.compare(0, str1.size(), str1) == 0 &&
         str2.compare(str2.size() - str1.size(), str1.size(), str1) == 0;
}

int countPrefixSuffixPairsImpl(std::vector<std::string>& words) {
  const int n = static_cast<int>(words.size());
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (isPrefixAndSuffix(words[i], words[j])) {
        ++count;
      }
    }
  }
  return count;
}

}  // namespace

CountPrefixAndSuffixPairsISolution::CountPrefixAndSuffixPairsISolution() {
  setMetaInfo({.id = 3042,
               .title = "Count Prefix and Suffix Pairs I",
               .url = "https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/"});
  registerStrategy({.name = "BruteForcePairScan",
                    .expected = "Accepted",
                    .time_complexity = "O(n^2 * L)",
                    .space_complexity = "O(1)",
                    .tags = {"Array", "String"}},
                   countPrefixSuffixPairsImpl);
}

int CountPrefixAndSuffixPairsISolution::countPrefixSuffixPairs(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace problem_3042
}  // namespace leetcode
