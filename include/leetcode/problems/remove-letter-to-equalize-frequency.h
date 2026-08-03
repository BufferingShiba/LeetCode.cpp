#ifndef LEETCODE_PROBLEMS_REMOVE_LETTER_TO_EQUALIZE_FREQUENCY_H__
#define LEETCODE_PROBLEMS_REMOVE_LETTER_TO_EQUALIZE_FREQUENCY_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2423 {

class RemoveLetterToEqualizeFrequencySolution
    : public SolutionBase<std::function<bool(std::string)>> {
 public:
  RemoveLetterToEqualizeFrequencySolution();

  bool equalFrequency(std::string word);
};

}  // namespace problem_2423
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_REMOVE_LETTER_TO_EQUALIZE_FREQUENCY_H__
