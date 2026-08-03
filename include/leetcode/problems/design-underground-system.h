#ifndef LEETCODE_PROBLEMS_DESIGN_UNDERGROUND_SYSTEM_H__
#define LEETCODE_PROBLEMS_DESIGN_UNDERGROUND_SYSTEM_H__

#include <string>
#include <unordered_map>
#include <utility>

namespace problem_1396 {

class UndergroundSystem {
 public:
  UndergroundSystem();

  void checkIn(int id, const std::string& stationName, int t);

  void checkOut(int id, const std::string& stationName, int t);

  double getAverageTime(const std::string& startStation,
                        const std::string& endStation);

 private:
  // Customer id -> (station where checked in, check-in time)
  std::unordered_map<int, std::pair<std::string, int>> checkIns_;
  // "start -> end" key -> (totalTime, tripCount)
  std::unordered_map<std::string, std::pair<long long, int>> stats_;
};

}  // namespace problem_1396

#endif  // LEETCODE_PROBLEMS_DESIGN_UNDERGROUND_SYSTEM_H__
