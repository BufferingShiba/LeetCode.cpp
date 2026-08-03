#include "leetcode/problems/replace-question-marks-in-string-to-minimize-its-value.h"

#include <algorithm>
#include <cstddef>
#include <queue>
#include <string>
#include <utility>
#include <vector>

namespace leetcode {
namespace problem_3081 {
namespace {

// The value of a string t equals the number of equal pairs (i < j) with
// t[i] == t[j], i.e. sum over characters c of C(N_c, 2) where N_c is the total
// count of c. This is independent of the ordering of characters.
//
// Strategy:
//  1. Greedily build the optimal multiset of replacement characters: repeat k
//     times, each time picking the character with the smallest current count
//     (ties broken by smallest letter) and incrementing it. This minimizes the
//     final total counts -> minimizes value.
//  2. Sort the chosen characters ascending and place them left-to-right into
//     the '?' positions. Since value is order-independent, this gives the
//     lexicographically smallest result among all optimal solutions.
std::string minimizeStringValueImpl(std::string s) {
  std::vector<int> count(26, 0);
  for (char ch : s) {
    if (ch != '?') {
      ++count[ch - 'a'];
    }
  }

  using Entry = std::pair<int, int>;  // (count, char index)
  std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> pq;
  for (int i = 0; i < 26; ++i) {
    pq.emplace(count[i], i);
  }

  std::vector<char> choices;
  for (char ch : s) {
    if (ch == '?') {
      auto [c, idx] = pq.top();
      pq.pop();
      choices.push_back(static_cast<char>('a' + idx));
      pq.emplace(c + 1, idx);
    }
  }

  // Sort chosen characters ascending so that earlier '?' get smaller letters.
  std::sort(choices.begin(), choices.end());

  std::size_t j = 0;
  for (char& ch : s) {
    if (ch == '?') {
      ch = choices[j++];
    }
  }
  return s;
}

}  // namespace

ReplaceQuestionMarksInStringToMinimizeItsValueSolution::
    ReplaceQuestionMarksInStringToMinimizeItsValueSolution() {
  setMetaInfo({.id = 3081,
               .title = "Replace Question Marks in String to Minimize Its Value",
               .url = "https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/"});

  registerStrategy(
      {.name = "greedy-minheap",
       .expected = "Accepted",
       .time_complexity = "O(n*log26)",
       .space_complexity = "O(1)",
       .tags = {"Hash Table", "String", "Greedy", "Sorting",
                "Heap (Priority Queue)", "Counting"}},
      minimizeStringValueImpl);
}

std::string ReplaceQuestionMarksInStringToMinimizeItsValueSolution::
    minimizeStringValue(std::string s) {
  return getSolution()(std::move(s));
}

}  // namespace problem_3081
}  // namespace leetcode
