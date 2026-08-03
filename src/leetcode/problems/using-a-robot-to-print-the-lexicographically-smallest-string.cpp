#include "leetcode/problems/using-a-robot-to-print-the-lexicographically-smallest-string.h"

#include <stack>
#include <string>

namespace leetcode {
namespace problem_2434 {

namespace {

std::string robotWithStringImpl(std::string s) {
  int cnt[26] = {};
  for (char c : s) {
    ++cnt[c - 'a'];
  }

  // The smallest character still present in the unprocessed suffix of s.
  char minChar = 'a';
  while (minChar <= 'z' && cnt[minChar - 'a'] == 0) {
    ++minChar;
  }

  std::string result;
  result.reserve(s.size());

  std::stack<char> st;

  for (char c : s) {
    st.push(c);
    --cnt[c - 'a'];

    // Advance minChar if the current smallest has been exhausted.
    while (minChar <= 'z' && cnt[minChar - 'a'] == 0) {
      ++minChar;
    }

    // Pop from stack while the top is not larger than the smallest
    // remaining character. When minChar > 'z' (nothing left), pop all.
    while (!st.empty() && st.top() <= minChar) {
      result.push_back(st.top());
      st.pop();
    }
  }

  return result;
}

}  // namespace

UsingARobotToPrintTheLexicographicallySmallestStringSolution::
    UsingARobotToPrintTheLexicographicallySmallestStringSolution() {
  setMetaInfo({.id = 2434,
               .title = "Using a Robot to Print the Lexicographically "
                        "Smallest String",
               .url = "https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/"});

  registerStrategy(
      {.name = "Greedy Stack",
       .expected = "Accepted",
       .time_complexity = "O(n)",
       .space_complexity = "O(n)",
       .tags = {"Hash Table", "String", "Stack", "Greedy"}},
      robotWithStringImpl);

  setDefaultStrategy();
}

std::string
UsingARobotToPrintTheLexicographicallySmallestStringSolution::robotWithString(
    std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_2434
}  // namespace leetcode
