#include "leetcode/problems/find-the-encrypted-string.h"

namespace leetcode::problem_3210 {

static std::string getEncryptedStringImpl(std::string s, int k) {
  int n = static_cast<int>(s.size());
  std::string result(n, ' ');
  for (int i = 0; i < n; ++i) {
    result[i] = s[(i + k) % n];
  }
  return result;
}

FindTheEncryptedStringSolution::FindTheEncryptedStringSolution() {
  setMetaInfo({.id = 3210,
               .title = "Find the Encrypted String",
               .url = "https://leetcode.com/problems/find-the-encrypted-string/"});
  registerStrategy({.name = "CyclicIndex",
                    .expected = "Accepted",
                    .time_complexity = "O(n)",
                    .space_complexity = "O(n)",
                    .tags = {"String"}},
                   getEncryptedStringImpl);
}

std::string FindTheEncryptedStringSolution::getEncryptedString(std::string s, int k) {
  return getSolution()(s, k);
}

}  // namespace leetcode::problem_3210
