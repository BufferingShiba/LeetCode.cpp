#include "leetcode/problems/bus-routes.h"

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace leetcode {
namespace problem_815 {

static int numBusesToDestinationImpl(std::vector<std::vector<int>>& routes,
                                     int source, int target) {
  if (source == target) return 0;

  // Build stop -> list of bus indices
  std::unordered_map<int, std::vector<int>> stop_to_buses;
  for (int i = 0; i < static_cast<int>(routes.size()); ++i) {
    for (int stop : routes[i]) {
      stop_to_buses[stop].push_back(i);
    }
  }

  // Source stop not served by any bus
  if (stop_to_buses.find(source) == stop_to_buses.end()) return -1;

  std::vector<bool> visited_bus(routes.size(), false);
  std::unordered_set<int> visited_stop;
  std::queue<int> bus_q;

  visited_stop.insert(source);
  for (int bus : stop_to_buses[source]) {
    visited_bus[bus] = true;
    bus_q.push(bus);
  }

  int buses = 1;
  while (!bus_q.empty()) {
    int sz = static_cast<int>(bus_q.size());
    for (int i = 0; i < sz; ++i) {
      int bus = bus_q.front();
      bus_q.pop();
      for (int stop : routes[bus]) {
        if (stop == target) return buses;
        if (visited_stop.count(stop)) continue;
        visited_stop.insert(stop);
        for (int next_bus : stop_to_buses[stop]) {
          if (!visited_bus[next_bus]) {
            visited_bus[next_bus] = true;
            bus_q.push(next_bus);
          }
        }
      }
    }
    ++buses;
  }

  return -1;
}

BusRoutesSolution::BusRoutesSolution() {
  setMetaInfo(
      {.id = 815, .title = "Bus Routes",
       .url = "https://leetcode.com/problems/bus-routes/"});
  registerStrategy(
      {.name = "BFS on Buses",
       .expected = "Accepted",
       .time_complexity = "O(N)",
       .space_complexity = "O(N)",
       .tags = {"Array", "Hash Table", "Breadth-First Search"}},
      numBusesToDestinationImpl);
}

int BusRoutesSolution::numBusesToDestination(
    std::vector<std::vector<int>>& routes, int source, int target) {
  return getSolution()(routes, source, target);
}

}  // namespace problem_815
}  // namespace leetcode
