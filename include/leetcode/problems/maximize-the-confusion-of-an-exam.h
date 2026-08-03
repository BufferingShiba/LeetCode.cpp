#include "leetcode/core.h"

namespace leetcode {
namespace problem_2024 {

using Func = std::function<int(string, int)>;

class MaximizeTheConfusionOfAnExamSolution : public SolutionBase<Func> {
 public:
  //! 2024. Maximize the Confusion of an Exam
  //! https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
  int maxConsecutiveAnswers(string answerKey, int k);

  MaximizeTheConfusionOfAnExamSolution();
};

}  // namespace problem_2024
}  // namespace leetcode
