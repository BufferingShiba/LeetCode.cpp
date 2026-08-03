#include <gtest/gtest.h>

#include <algorithm>
#include <vector>
#include <string>
#include <functional>

#include "leetcode/problems/two-letter-card-game.h"

namespace leetcode::problem_3664 {
namespace {

class TwoLetterCardGameTest : public ::testing::TestWithParam<std::string> {
 protected:
  TwoLetterCardGameSolution solution;

  void SetUp() override { solution.setStrategy(GetParam()); }

  int run(std::vector<std::string> cards, char x) {
    return solution.score(cards, x);
  }
};

// Brute-force maximum matching for small decks; used to validate the greedy.
int bruteMaxPairs(const std::vector<std::string>& cards, char x) {
  auto compatible = [x](const std::string& a, const std::string& b) {
    if ((a[0] != x && a[1] != x) || (b[0] != x && b[1] != x)) {
      return false;
    }
    int diff = (a[0] != b[0]) + (a[1] != b[1]);
    return diff == 1;
  };
  int n = static_cast<int>(cards.size());
  std::vector<int> match(n, 0);
  int best = 0;
  std::function<void(int, int)> dfs = [&](int idx, int cnt) {
    best = std::max(best, cnt);
    for (int i = idx; i < n; ++i) {
      if (match[i]) continue;
      for (int j = i + 1; j < n; ++j) {
        if (match[j]) continue;
        if (compatible(cards[i], cards[j])) {
          match[i] = match[j] = 1;
          dfs(i + 1, cnt + 1);
          match[i] = match[j] = 0;
        }
      }
    }
  };
  dfs(0, 0);
  return best;
}

}  // namespace

TEST_P(TwoLetterCardGameTest, Example1) {
  EXPECT_EQ(run({"aa", "ab", "ba", "ac"}, 'a'), 2);
}

TEST_P(TwoLetterCardGameTest, Example2) {
  EXPECT_EQ(run({"aa", "ab", "ba"}, 'a'), 1);
}

TEST_P(TwoLetterCardGameTest, Example3) {
  EXPECT_EQ(run({"aa", "ab", "ba", "ac"}, 'b'), 0);
}

TEST_P(TwoLetterCardGameTest, BridgeOnly) {
  // Only xx cards: two identical cards never pair.
  EXPECT_EQ(run({"xx", "xx", "xx"}, 'x'), 0);
}

TEST_P(TwoLetterCardGameTest, BridgeAbsorbsSingleType) {
  // xa xa xa (3 same-type A) + 2 xx cards -> pair each xx with one xa = 2 pairs.
  std::vector<std::string> cards = {"xa", "xa", "xa", "xx", "xx"};
  EXPECT_EQ(run(cards, 'x'), 2);
}

TEST_P(TwoLetterCardGameTest, UniversalBridgeRebalancesPool) {
  // Matching xa/xb greedily first leaves too few useful cards for xx.  The
  // optimal five pairs use all three types in a balanced multipartite match.
  std::vector<std::string> cards = {
      "xa", "xa", "xa", "xa", "xb", "xb", "xb", "xx", "xx", "xx"};
  EXPECT_EQ(run(cards, 'x'), 5);
}

TEST_P(TwoLetterCardGameTest, SameTypeCannotPair) {
  // xa xa + xb xb -> (xa,xb),(xa,xb) = 2 pairs.
  std::vector<std::string> cards = {"xa", "xa", "xb", "xb"};
  EXPECT_EQ(run(cards, 'x'), 2);
}

TEST_P(TwoLetterCardGameTest, NoXSpansTwoPools) {
  // xa + ax : differ in both positions -> not compatible, no xx bridge.
  std::vector<std::string> cards = {"xa", "ax"};
  EXPECT_EQ(run(cards, 'x'), 0);
}

TEST_P(TwoLetterCardGameTest, GreedyMatchesBruteForce) {
  // Small randomized synthetic decks: greedy result must equal brute force.
  const std::vector<std::string> pool = {"aa", "ab", "ba", "bx", "xx"};
  for (int trial = 0; trial < 40; ++trial) {
    std::vector<std::string> cards;
    int m = 2 + (trial % 6);  // deck size between 2 and 7
    for (int k = 0; k < m; ++k) {
      cards.push_back(pool[(trial * 7 + k) % pool.size()]);
    }
    char x = "ab"[trial % 2];
    int expected = bruteMaxPairs(cards, x);
    std::string dbg;
    for (auto& c : cards) dbg += c + ",";
    EXPECT_EQ(run(cards, x), expected) << "cards=[" << dbg << "] x=" << x;
  }
}

INSTANTIATE_TEST_SUITE_P(
    TwoLetterCardGameTests, TwoLetterCardGameTest,
    ::testing::ValuesIn(TwoLetterCardGameSolution().getStrategyNames()));

}  // namespace leetcode::problem_3664
