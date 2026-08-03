#ifndef LEETCODE_PROBLEMS_K_TH_SYMBOL_IN_GRAMMAR_H__
#define LEETCODE_PROBLEMS_K_TH_SYMBOL_IN_GRAMMAR_H__

#include "leetcode/core.h"

namespace leetcode {
namespace problem_779 {

using Func = std::function<int(int, int)>;

class KThSymbolInGrammarSolution : public SolutionBase<Func> {
 public:
  KThSymbolInGrammarSolution();

  int kthGrammar(int n, int k);
};

}  // namespace problem_779
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_K_TH_SYMBOL_IN_GRAMMAR_H__
