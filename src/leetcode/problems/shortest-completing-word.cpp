#include "leetcode/problems/shortest-completing-word.h"

#include <array>
#include <cctype>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_748 {

namespace {

// Count lowercase letters in the license plate (ignoring numbers/spaces/case).
std::array<int, 26> plateCounts(const std::string& licensePlate) {
  std::array<int, 26> cnt{};
  for (char ch : licensePlate) {
    if (std::isalpha(static_cast<unsigned char>(ch))) {
      ++cnt[std::tolower(static_cast<unsigned char>(ch)) - 'a'];
    }
  }
  return cnt;
}

bool covers(const std::array<int, 26>& wordCnt,
            const std::array<int, 26>& need) {
  for (int i = 0; i < 26; ++i) {
    if (wordCnt[i] < need[i]) {
      return false;
    }
  }
  return true;
}

std::string shortestCompletingWordImpl(std::string licensePlate,
                                       std::vector<std::string>& words) {
  std::array<int, 26> need = plateCounts(licensePlate);
  std::string result;
  for (const std::string& w : words) {
    if (!result.empty() && w.size() >= result.size()) {
      continue;
    }
    std::array<int, 26> wc{};
    for (char ch : w) {
      ++wc[ch - 'a'];
    }
    if (covers(wc, need)) {
      result = w;
    }
  }
  return result;
}

}  // namespace

ShortestCompletingWordSolution::ShortestCompletingWordSolution() {
  setMetaInfo({.id = 748,
               .title = "Shortest Completing Word",
               .url = "https://leetcode.com/problems/shortest-completing-word/"});
  registerStrategy(
      {.name = "CharCount", .expected = "Accepted",
       .time_complexity = "O(L + N*W)", .space_complexity = "O(1)",
       .tags = {"Array", "Hash Table", "String"}},
      shortestCompletingWordImpl);
}

std::string ShortestCompletingWordSolution::shortestCompletingWord(
    std::string licensePlate, std::vector<std::string>& words) {
  return getSolution()(licensePlate, words);
}

}  // namespace problem_748
}  // namespace leetcode
