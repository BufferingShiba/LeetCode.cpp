#ifndef LEETCODE_PROBLEMS_STUDENT_ATTENDANCE_RECORD_I_H__
#define LEETCODE_PROBLEMS_STUDENT_ATTENDANCE_RECORD_I_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_551 {

using Func = std::function<bool(std::string)>;

class StudentAttendanceRecordISolution : public SolutionBase<Func> {
 public:
  StudentAttendanceRecordISolution();

  bool checkRecord(std::string s);
};

}  // namespace problem_551
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_STUDENT_ATTENDANCE_RECORD_I_H__
