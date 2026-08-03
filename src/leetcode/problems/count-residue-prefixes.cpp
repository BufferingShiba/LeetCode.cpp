#include "leetcode/problems/count-residue-prefixes.h"

namespace leetcode {
namespace problem_3803 {

namespace {

int residuePrefixesImpl(std::string s) {
  bool seen[26] = {false};
  int distinct = 0;
  int count = 0;
  for (int i = 0; i < static_cast<int>(s.size()); ++i) {
    int idx = s[i] - 'a';
    if (!seen[idx]) {
      seen[idx] = true;
      ++distinct;
    }
    if (distinct == (i + 1) % 3) {
      ++count;
    }
  }
  return count;
}

}  // namespace

CountResiduePrefixesSolution::CountResiduePrefixesSolution() {
  setMetaInfo({.id = 3803,
               .title = "Count Residue Prefixes",
               .url = "https://leetcode.com/problems/count-residue-prefixes/"});
  registerStrategy({.name = "linear-scan",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(1)",
                    .tags = {"Hash Table", "String"}},
                   residuePrefixesImpl);
}

int CountResiduePrefixesSolution::residuePrefixes(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_3803
}  // namespace leetcode
