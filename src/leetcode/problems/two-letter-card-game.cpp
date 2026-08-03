#include "leetcode/problems/two-letter-card-game.h"

#include <algorithm>
#include <array>

namespace leetcode::problem_3664 {

namespace {

// Maximum number of pairs in one pool after assigning `have` universal "xx"
// cards to it.  The pool is a complete multipartite graph: cards of the same
// type cannot pair, while cards from different types can.  Therefore the
// matching size is limited by both half of the pool and the cards outside its
// largest part.
int maxMatchInPool(const std::array<int, 26>& cnt, int have) {
  long long total = have;
  long long largestPart = have;
  for (const int c : cnt) {
    total += c;
    largestPart = std::max(largestPart, static_cast<long long>(c));
  }
  return static_cast<int>(std::min(total / 2, total - largestPart));
}

int scoreImpl(std::vector<std::string>& cards, char x) {
  // Only cards containing 'x' participate.
  // A-type: "xc" (x at position 0, other letter c).
  // B-type: "cx" (x at position 1, other letter c).
  // "xx" (c == x in both) is the unique bridging card.
  std::array<int, 26> cntA{};  // keyed by the non-x letter of pos1.
  std::array<int, 26> cntB{};  // keyed by the non-x letter of pos0.
  long long xxc = 0;

  for (const std::string& s : cards) {
    char a = s[0], b = s[1];
    if (a == x && b == x) {
      ++xxc;
    } else if (a == x) {
      ++cntA[b - 'a'];
    } else if (b == x) {
      ++cntB[a - 'a'];
    }
    // else: card does not contain x, ignore.
  }

  // Splitting the universal cards between the two one-sided pools matters:
  // matching each pool before using "xx" can waste a card from a smaller
  // type and miss an additional pair.  Try every possible split.
  int answer = 0;
  for (int takeA = 0; takeA <= xxc; ++takeA) {
    answer = std::max(
        answer, maxMatchInPool(cntA, takeA) +
                    maxMatchInPool(cntB, xxc - takeA));
  }
  return answer;
}

}  // namespace

int TwoLetterCardGameSolution::score(std::vector<std::string>& cards, char x) {
  return getSolution()(cards, x);
}

TwoLetterCardGameSolution::TwoLetterCardGameSolution() {
  setMetaInfo({3664, "Two-Letter Card Game",
               "https://leetcode.com/problems/two-letter-card-game/"});
  registerStrategy(
      {"greedy-pool-match", "Accepted", "O(n)", "O(1)",
       {"Array", "Hash Table", "String", "Counting", "Enumeration"}},
      scoreImpl);
}

}  // namespace leetcode::problem_3664
