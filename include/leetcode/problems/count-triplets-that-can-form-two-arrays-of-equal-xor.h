#include "leetcode/core.h"

namespace leetcode {
namespace problem_1442 {

using Func = std::function<int(vector<int>&)>;

class CountTripletsThatCanFormTwoArraysOfEqualXorSolution : public SolutionBase<Func> {
 public:
  //! 1442. Count Triplets That Can Form Two Arrays of Equal XOR
  //! https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
  int countTriplets(vector<int>& arr);

  CountTripletsThatCanFormTwoArraysOfEqualXorSolution();
};

}  // namespace problem_1442
}  // namespace leetcode
