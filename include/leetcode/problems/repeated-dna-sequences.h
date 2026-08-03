#ifndef LEETCODE_PROBLEMS_REPEATED_DNA_SEQUENCES_H_
#define LEETCODE_PROBLEMS_REPEATED_DNA_SEQUENCES_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode::problem_187 {

using Func = std::function<std::vector<std::string>(std::string)>;

class RepeatedDnaSequencesSolution : public SolutionBase<Func> {
 public:
  RepeatedDnaSequencesSolution();

  std::vector<std::string> findRepeatedDnaSequences(std::string s);
};

}  // namespace leetcode::problem_187

#endif  // LEETCODE_PROBLEMS_REPEATED_DNA_SEQUENCES_H_
