#ifndef LEETCODE_PROBLEMS_CATEGORIZE_BOX_ACCORDING_TO_CRITERIA_H__
#define LEETCODE_PROBLEMS_CATEGORIZE_BOX_ACCORDING_TO_CRITERIA_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2525 {

using Func = std::function<std::string(int, int, int, int)>;

class CategorizeBoxAccordingToCriteriaSolution
    : public SolutionBase<Func> {
 public:
  CategorizeBoxAccordingToCriteriaSolution();
  std::string categorizeBox(int length, int width, int height, int mass);
};

}  // namespace problem_2525
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_CATEGORIZE_BOX_ACCORDING_TO_CRITERIA_H__
