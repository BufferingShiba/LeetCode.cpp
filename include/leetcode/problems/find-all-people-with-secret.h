#include "leetcode/core.h"

namespace leetcode {
namespace problem_2092 {

using Func = std::function<vector<int>(int, vector<vector<int>>&, int)>;

class FindAllPeopleWithSecretSolution : public SolutionBase<Func> {
 public:
  //! 2092. Find All People With Secret
  //! https://leetcode.com/problems/find-all-people-with-secret/
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                            int firstPerson);

  FindAllPeopleWithSecretSolution();
};

}  // namespace problem_2092
}  // namespace leetcode