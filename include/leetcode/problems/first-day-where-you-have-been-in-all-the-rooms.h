#ifndef LEETCODE_PROBLEMS_FIRST_DAY_WHERE_YOU_HAVE_BEEN_IN_ALL_THE_ROOMS_H_
#define LEETCODE_PROBLEMS_FIRST_DAY_WHERE_YOU_HAVE_BEEN_IN_ALL_THE_ROOMS_H_

#include "leetcode/core.h"

namespace leetcode {
namespace problem_1997 {

using Func = std::function<int(std::vector<int>&)>;

class FirstDayWhereYouHaveBeenInAllTheRoomsSolution : public SolutionBase<Func> {
 public:
  FirstDayWhereYouHaveBeenInAllTheRoomsSolution();
  int firstDayBeenInAllRooms(std::vector<int>& nextVisit);
};

}  // namespace problem_1997
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_FIRST_DAY_WHERE_YOU_HAVE_BEEN_IN_ALL_THE_ROOMS_H_
