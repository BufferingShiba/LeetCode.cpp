#ifndef LEETCODE_PROBLEMS_REWARD_TOP_K_STUDENTS_H_
#define LEETCODE_PROBLEMS_REWARD_TOP_K_STUDENTS_H_

#include "leetcode/core.h"

#include <functional>
#include <string>
#include <vector>

namespace leetcode {
namespace problem_2512 {

using Func = std::function<std::vector<int>(std::vector<std::string>&,
                                            std::vector<std::string>&,
                                            std::vector<std::string>&,
                                            std::vector<int>&, int)>;

class RewardTopKStudentsSolution : public SolutionBase<Func> {
 public:
  RewardTopKStudentsSolution();

  std::vector<int> topStudents(std::vector<std::string>& positive_feedback,
                               std::vector<std::string>& negative_feedback,
                               std::vector<std::string>& report,
                               std::vector<int>& student_id, int k);
};

}  // namespace problem_2512
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REWARD_TOP_K_STUDENTS_H_
