#include "leetcode/core.h"

namespace leetcode {
namespace problem_1838 {

using Func = std::function<int(vector<int>&, int)>;

class FrequencyOfTheMostFrequentElementSolution : public SolutionBase<Func> {
 public:
  //! 1838. Frequency of the Most Frequent Element
  //! https://leetcode.com/problems/frequency-of-the-most-frequent-element/
  int maxFrequency(vector<int>& nums, int k);

  FrequencyOfTheMostFrequentElementSolution();
};

}  // namespace problem_1838
}  // namespace leetcode
