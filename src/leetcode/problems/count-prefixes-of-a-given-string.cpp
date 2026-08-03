#include "leetcode/problems/count-prefixes-of-a-given-string.h"

#include <string>
#include <vector>

namespace leetcode {
namespace problem_2255 {

namespace {

int countPrefixesImpl(std::vector<std::string>& words, std::string s) {
  int count = 0;
  for (const std::string& word : words) {
    if (s.size() >= word.size() && s.compare(0, word.size(), word) == 0) {
      ++count;
    }
  }
  return count;
}

}  // namespace

int CountPrefixesOfAGivenString::countPrefixes(std::vector<std::string>& words,
                                               std::string s) {
  return getSolution()(words, s);
}

CountPrefixesOfAGivenString::CountPrefixesOfAGivenString() {
  setMetaInfo({.id = 2255,
               .title = "Count Prefixes of a Given String",
               .url = "https://leetcode.com/problems/count-prefixes-of-a-given-string/"});
  registerStrategy({
                        .name = "LinearScan",
                        .expected = "Accepted",
                        .time_complexity = "O(n * L)",
                        .space_complexity = "O(1)",
                        .tags = {"Array", "String"},
                    },
                    countPrefixesImpl);
}

}  // namespace problem_2255
}  // namespace leetcode
