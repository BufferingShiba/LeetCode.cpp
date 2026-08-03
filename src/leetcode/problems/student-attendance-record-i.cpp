#include "leetcode/problems/student-attendance-record-i.h"

namespace leetcode {
namespace problem_551 {

namespace {

bool checkRecordImpl(std::string s) {
  int absences = 0;
  int consecutiveLate = 0;
  for (char c : s) {
    if (c == 'A') {
      ++absences;
      if (absences >= 2) return false;
      consecutiveLate = 0;
    } else if (c == 'L') {
      ++consecutiveLate;
      if (consecutiveLate >= 3) return false;
    } else {
      consecutiveLate = 0;
    }
  }
  return true;
}

}  // namespace

StudentAttendanceRecordISolution::StudentAttendanceRecordISolution() {
  setMetaInfo({551, "Student Attendance Record I",
               "https://leetcode.com/problems/student-attendance-record-i/"});
  registerStrategy({
      .name = "SinglePass",
      .expected = "Accepted",
      .time_complexity = "O(n)",
      .space_complexity = "O(1)",
      .tags = {"String"},
      .notes = "One-pass scan counting absences and consecutive lates.",
  }, checkRecordImpl);
}

bool StudentAttendanceRecordISolution::checkRecord(std::string s) {
  return getSolution()(s);
}

}  // namespace problem_551
}  // namespace leetcode
