#ifndef LEETCODE_PROBLEMS_MY_CALENDAR_III_H__
#define LEETCODE_PROBLEMS_MY_CALENDAR_III_H__

#include <map>

namespace leetcode {
namespace problem_732 {

class MyCalendarThree {
 public:
  MyCalendarThree();

  int book(int startTime, int endTime);

 private:
  std::map<int, int> delta_;
};

}  // namespace problem_732
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_MY_CALENDAR_III_H__
