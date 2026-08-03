#include "leetcode/problems/airplane-seat-assignment-probability.h"

namespace leetcode {
namespace problem_1227 {

namespace {

// 经典结论：第 1 个乘客随机选座后，
//   - n == 1 时，第 1 人只能坐座位 1，概率为 1。
//   - n >= 2 时，整个过程始终存在若干“错误座位”。每当某个坐错座位的
//     乘客在剩余可用座位里随机选择时，选中座位 1 与选中座位 n 的概率
//     始终相等；若有人选中座位 1 则后续全部归位，若选中座位 n 则第 n 人
//     无法坐到自己座位。由对称性可知概率恒为 1/2。
// 复杂度：O(1) 时间，O(1) 空间。
double nthPersonGetsNthSeatImpl(int n) {
  return n == 1 ? 1.0 : 0.5;
}

}  // namespace

AirplaneSeatAssignmentProbabilitySolution::
    AirplaneSeatAssignmentProbabilitySolution() {
  setMetaInfo({.id = 1227,
               .title = "Airplane Seat Assignment Probability",
               .url = "https://leetcode.com/problems/airplane-seat-assignment-probability/"});

  registerStrategy(
      {.name = "closedForm",
       .expected = "Accepted",
       .time_complexity = "O(1)",
       .space_complexity = "O(1)",
       .tags = {"Math", "Probability and Statistics", "Brainteaser"},
       .notes = "n==1 概率为 1；n>=2 恒为 1/2（对称性证明）"},
      nthPersonGetsNthSeatImpl);
}

double AirplaneSeatAssignmentProbabilitySolution::nthPersonGetsNthSeat(
    int n) {
  return getSolution()(n);
}

}  // namespace problem_1227
}  // namespace leetcode
