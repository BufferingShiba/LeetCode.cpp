#include "leetcode/problems/design-underground-system.h"

namespace problem_1396 {

namespace {

// Encode a station pair (start -> end) as a single string key.
inline std::string MakeKey(const std::string& start,
                           const std::string& end) {
  return start + " -> " + end;
}

}  // namespace

UndergroundSystem::UndergroundSystem() = default;

void UndergroundSystem::checkIn(int id, const std::string& stationName,
                                int t) {
  // A customer checks in at most once at a time.
  checkIns_[id] = std::make_pair(stationName, t);
}

void UndergroundSystem::checkOut(int id, const std::string& stationName,
                                 int t) {
  auto it = checkIns_.find(id);
  if (it == checkIns_.end()) {
    return;  // inconsistent call (not expected by constraints)
  }
  const std::string& startStation = it->second.first;
  int startTime = it->second.second;
  checkIns_.erase(it);

  std::string key = MakeKey(startStation, stationName);
  auto& entry = stats_[key];
  // entry.first accumulates total time, entry.second counts trips.
  entry.first += static_cast<long long>(t) - startTime;
  entry.second += 1;
}

double UndergroundSystem::getAverageTime(const std::string& startStation,
                                         const std::string& endStation) {
  std::string key = MakeKey(startStation, endStation);
  auto it = stats_.find(key);
  if (it == stats_.end() || it->second.second == 0) {
    return 0.0;  // not expected given constraints guarantee existence
  }
  return static_cast<double>(it->second.first) / it->second.second;
}

}  // namespace problem_1396
