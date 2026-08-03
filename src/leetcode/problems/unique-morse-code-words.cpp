#include "leetcode/problems/unique-morse-code-words.h"

#include <string>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_804 {
namespace {

const std::vector<std::string> kMorse = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

int uniqueMorseRepresentationsImpl(std::vector<std::string>& words) {
  std::unordered_set<std::string> seen;
  for (const std::string& word : words) {
    std::string encoded;
    for (char c : word) {
      encoded += kMorse[c - 'a'];
    }
    seen.insert(encoded);
  }
  return static_cast<int>(seen.size());
}

}  // namespace

UniqueMorseCodeWordsSolution::UniqueMorseCodeWordsSolution() {
  setMetaInfo({.id = 804,
               .title = "Unique Morse Code Words",
               .url = "https://leetcode.com/problems/unique-morse-code-words/"});
  registerStrategy(
      {.name = "HashSet",
       .expected = "Accepted",
       .time_complexity = "O(N*L)",
       .space_complexity = "O(N*L)",
       .tags = {"Array", "Hash Table", "String"}},
      uniqueMorseRepresentationsImpl);
}

int UniqueMorseCodeWordsSolution::uniqueMorseRepresentations(
    std::vector<std::string>& words) {
  return getSolution()(words);
}

}  // namespace problem_804
}  // namespace leetcode
