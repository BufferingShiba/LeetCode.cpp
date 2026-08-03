#include "leetcode/problems/can-make-palindrome-from-substring.h"

#include <bitset>

namespace leetcode::problem_1177 {

namespace {

std::vector<bool> canMakePaliQueriesImpl(std::string s,
                                         std::vector<std::vector<int>>& queries) {
  int n = static_cast<int>(s.size());

  // prefix_xor[i] = parity mask of first i characters
  std::vector<int> prefix_xor(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    int bit = s[i] - 'a';
    prefix_xor[i + 1] = prefix_xor[i] ^ (1 << bit);
  }

  std::vector<bool> answer;
  answer.reserve(queries.size());

  for (const auto& q : queries) {
    int left = q[0];
    int right = q[1];
    int k = q[2];

    int mask = prefix_xor[right + 1] ^ prefix_xor[left];
    int odd_count = std::bitset<32>(mask).count();

    answer.push_back(odd_count / 2 <= k);
  }

  return answer;
}

}  // namespace

CanMakePalindromeFromSubstringSolution::CanMakePalindromeFromSubstringSolution() {
  setMetaInfo({.id = 1177,
               .title = "Can Make Palindrome from Substring",
               .url = "https://leetcode.com/problems/can-make-palindrome-from-substring/"});

  registerStrategy(
      {.name = "Prefix XOR",
       .expected = "Accepted",
       .time_complexity = "O(n + q)",
       .space_complexity = "O(n)",
       .tags = {"Array", "Hash Table", "String", "Bit Manipulation", "Prefix Sum"}},
      canMakePaliQueriesImpl);
}

std::vector<bool> CanMakePalindromeFromSubstringSolution::canMakePaliQueries(
    std::string s, std::vector<std::vector<int>>& queries) {
  return getSolution()(s, queries);
}

}  // namespace leetcode::problem_1177
