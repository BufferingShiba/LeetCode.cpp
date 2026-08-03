#ifndef LEETCODE_3541_FIND_MOST_FREQUENT_VOWEL_AND_CONSONANT_H__
#define LEETCODE_3541_FIND_MOST_FREQUENT_VOWEL_AND_CONSONANT_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3541 {

using Func = std::function<int(std::string)>;

class FindMostFrequentVowelAndConsonantSolution
    : public SolutionBase<Func> {
 public:
  FindMostFrequentVowelAndConsonantSolution();

  int maxFreqSum(const std::string& s);

 private:
  static int countingApproach(const std::string& s);
};

}  // namespace problem_3541
}  // namespace leetcode

#endif  // LEETCODE_3541_FIND_MOST_FREQUENT_VOWEL_AND_CONSONANT_H__
