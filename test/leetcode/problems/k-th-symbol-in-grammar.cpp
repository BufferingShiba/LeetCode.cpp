#include <gtest/gtest.h>

#include "leetcode/problems/k-th-symbol-in-grammar.h"

using namespace leetcode::problem_779;

class KThSymbolInGrammarTest : public testing::TestWithParam<std::string> {
 protected:
  void SetUp() override { solution.setStrategy(GetParam()); }
  KThSymbolInGrammarSolution solution;
};

TEST_P(KThSymbolInGrammarTest, Example1) {
  EXPECT_EQ(solution.kthGrammar(1, 1), 0);
}

TEST_P(KThSymbolInGrammarTest, Example2) {
  EXPECT_EQ(solution.kthGrammar(2, 1), 0);
}

TEST_P(KThSymbolInGrammarTest, Example3) {
  EXPECT_EQ(solution.kthGrammar(2, 2), 1);
}

TEST_P(KThSymbolInGrammarTest, SelfAuthoredRow3) {
  // Row 3: 0 1 1 0
  EXPECT_EQ(solution.kthGrammar(3, 1), 0);
  EXPECT_EQ(solution.kthGrammar(3, 2), 1);
  EXPECT_EQ(solution.kthGrammar(3, 3), 1);
  EXPECT_EQ(solution.kthGrammar(3, 4), 0);
}

TEST_P(KThSymbolInGrammarTest, SelfAuthoredRow4) {
  // Row 4: 0 1 1 0 1 0 0 1
  EXPECT_EQ(solution.kthGrammar(4, 1), 0);
  EXPECT_EQ(solution.kthGrammar(4, 5), 1);
  EXPECT_EQ(solution.kthGrammar(4, 8), 1);
}

TEST_P(KThSymbolInGrammarTest, SelfAuthoredEdgeN30) {
  // n=30, k=1 始终为 0（第一个字符永远是 0）
  EXPECT_EQ(solution.kthGrammar(30, 1), 0);
  // n=30, k=2^29（最后一位），取决于 2^29-1 的 popcount 奇偶性
  int last = 1 << 29;  // 2^(30-1)
  EXPECT_EQ(solution.kthGrammar(30, last),
            solution.kthGrammar(30, last));  // 自身一致性
}

INSTANTIATE_TEST_SUITE_P(AllStrategies, KThSymbolInGrammarTest,
                         testing::ValuesIn(KThSymbolInGrammarSolution()
                                                .getStrategyNames()));
