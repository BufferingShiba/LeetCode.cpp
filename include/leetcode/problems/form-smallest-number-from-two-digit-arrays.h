#ifndef LEETCODE_PROBLEMS_FORM_SMALLEST_NUMBER_FROM_TWO_DIGIT_ARRAYS_H__
#define LEETCODE_PROBLEMS_FORM_SMALLEST_NUMBER_FROM_TWO_DIGIT_ARRAYS_H__

#include <functional>
#include <string>
#include <vector>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_2605 {

using Func = std::function<int(std::vector<int>&, std::vector<int>&)>;

class FormSmallestNumberFromTwoDigitArraysSolution
    : public SolutionBase<Func> {
 public:
  int minNumber(std::vector<int>& nums1, std::vector<int>& nums2);

  FormSmallestNumberFromTwoDigitArraysSolution();
};

}  // namespace problem_2605
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FORM_SMALLEST_NUMBER_FROM_TWO_DIGIT_ARRAYS_H__
