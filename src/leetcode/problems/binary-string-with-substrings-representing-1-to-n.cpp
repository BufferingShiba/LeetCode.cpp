#include "leetcode/problems/binary-string-with-substrings-representing-1-to-n.h"

#include <string>
#include <unordered_set>

namespace leetcode::problem_1016 {
namespace {

bool queryStringImpl(const std::string& s, int n) {
  const int len = static_cast<int>(s.size());
  // s 中不同整数子串（二进制长度 <= 30）去重后最多 len * 30 个。
  // 要覆盖 [1, n] 共 n 个不同整数，n 必须不超过该上界。
  if (n > len * 30) {
    return false;
  }
  std::unordered_set<int> seen;
  for (int i = 0; i < len; ++i) {
    int val = 0;
    for (int j = i; j < len && j - i + 1 <= 30; ++j) {
      val = (val << 1) | (s[j] - '0');
      if (val > n) {
        break;
      }
      if (val >= 1) {
        seen.insert(val);
      }
    }
  }
  return static_cast<int>(seen.size()) == n;
}

}  // namespace

BinaryStringWithSubstringsRepresenting1ToNSolution::
    BinaryStringWithSubstringsRepresenting1ToNSolution() {
  setMetaInfo({.id = 1016,
               .title = "Binary String With Substrings Representing 1 To N",
               .url = "https://leetcode.com/problems/"
                      "binary-string-with-substrings-representing-1-to-n/"});
  registerStrategy(
      {.name = "enumerate-substrings",
       .expected = "Accepted",
       .time_complexity = "O(|s| * 30)",
       .space_complexity = "O(|s| * 30)",
       .tags = {"Hash Table", "String", "Sliding Window"},
       .notes =
           "枚举 s 中所有长度不超过 30 的连续子串并转成整数存 set；由于不同"
           "整数子串最多 |s|*30 个，n 超过该上界时直接 false，否则校验 "
           "[1,n] 是否全部被覆盖。"},
      queryStringImpl);
}

bool BinaryStringWithSubstringsRepresenting1ToNSolution::queryString(
    const std::string& s, int n) {
  return getSolution()(s, n);
}

}  // namespace leetcode::problem_1016
