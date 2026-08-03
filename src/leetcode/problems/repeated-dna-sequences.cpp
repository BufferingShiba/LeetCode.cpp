#include "leetcode/problems/repeated-dna-sequences.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace leetcode::problem_187 {

static std::vector<std::string> findRepeatedDnaSequencesImpl(std::string s) {
  if (s.length() < 10) return {};

  auto charToVal = [](char c) -> uint32_t {
    switch (c) {
      case 'A': return 0;
      case 'C': return 1;
      case 'G': return 2;
      case 'T': return 3;
      default:  return 0;
    }
  };

  std::unordered_map<uint32_t, int> count;
  std::vector<std::string> result;

  uint32_t hash = 0;
  for (int i = 0; i < 10; ++i) {
    hash = (hash << 2) | charToVal(s[i]);
  }
  count[hash] = 1;

  const uint32_t mask = (1U << 20) - 1;  // low 20 bits
  for (size_t i = 10; i < s.length(); ++i) {
    hash = ((hash << 2) | charToVal(s[i])) & mask;
    int& cnt = count[hash];
    if (++cnt == 2) {
      result.push_back(s.substr(i - 9, 10));
    }
  }

  return result;
}

RepeatedDnaSequencesSolution::RepeatedDnaSequencesSolution() {
  setMetaInfo({.id = 187,
               .title = "Repeated DNA Sequences",
               .url = "https://leetcode.com/problems/repeated-dna-sequences/"});
  registerStrategy(
      {.name = "BitManipulation",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "Bit Manipulation", "Sliding Window",
                "Rolling Hash"}},
      findRepeatedDnaSequencesImpl);
}

std::vector<std::string> RepeatedDnaSequencesSolution::findRepeatedDnaSequences(
    std::string s) {
  return getSolution()(s);
}

}  // namespace leetcode::problem_187
