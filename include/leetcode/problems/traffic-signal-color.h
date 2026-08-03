#ifndef LEETCODE_PROBLEMS_TRAFFIC_SIGNAL_COLOR_H__
#define LEETCODE_PROBLEMS_TRAFFIC_SIGNAL_COLOR_H__

#include "leetcode/core.h"

#include <functional>
#include <string>

namespace leetcode {
namespace problem_3894 {

using Func = std::function<std::string(int)>;

class TrafficSignalColorSolution : public SolutionBase<Func> {
 public:
  TrafficSignalColorSolution() {
    setMetaInfo({.id = 3894,
                 .title = "Traffic Signal Color",
                 .url = "https://leetcode.com/problems/traffic-signal-color/"});
    registerStrategy({.name = "Simulation",
                      .expected = "Accepted",
                      .time_complexity = "O(1)",
                      .space_complexity = "O(1)",
                      .tags = {"Math", "String", "Simulation"}},
                     trafficSignalImpl);
  }

  std::string trafficSignal(int timer) { return getSolution()(timer); }

 private:
  static std::string trafficSignalImpl(int timer) {
    if (timer == 0) {
      return "Green";
    }
    if (timer == 30) {
      return "Orange";
    }
    if (timer > 30 && timer <= 90) {
      return "Red";
    }
    return "Invalid";
  }
};

}  // namespace problem_3894
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_TRAFFIC_SIGNAL_COLOR_H__
