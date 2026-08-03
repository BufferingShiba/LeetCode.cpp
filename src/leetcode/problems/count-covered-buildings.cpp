#include "leetcode/problems/count-covered-buildings.h"

#include <unordered_map>
#include <vector>

namespace leetcode::problem_3531 {
namespace {

// Group buildings by their y coordinate (column): the buildings sharing a y
// value are aligned vertically, so their x range determines who has a building
// above/below. Group by x coordinate (row): the x-sharing buildings are aligned
// horizontally, so their y range determines who has a building left/right.
//
// A building [x, y] is covered iff:
//   - in its y-group there is a smaller x (above) and a larger x (below), and
//   - in its x-group there is a smaller y (left) and a larger y (right).
//
// Because all coordinates (x, y) are unique there is no ambiguity.
int countCoveredBuildingsImpl(int /*n*/,
                              std::vector<std::vector<int>>& buildings) {
    std::unordered_map<int, std::pair<int, int>> colRange;  // y -> {min_x, max_x}
    std::unordered_map<int, std::pair<int, int>> rowRange;  // x -> {min_y, max_y}

    for (const auto& b : buildings) {
        int x = b[0];
        int y = b[1];

        auto& col = colRange[y];
        auto& row = rowRange[x];

        if (col.second == 0) {  // first visit for this y-group
            col = {x, x};
        } else {
            if (x < col.first) col.first = x;
            if (x > col.second) col.second = x;
        }

        if (row.second == 0) {  // first visit for this x-group
            row = {y, y};
        } else {
            if (y < row.first) row.first = y;
            if (y > row.second) row.second = y;
        }
    }

    int count = 0;
    for (const auto& b : buildings) {
        int x = b[0];
        int y = b[1];

        const auto& col = colRange[y];  // same y: above/below
        const auto& row = rowRange[x];  // same x: left/right

        bool verticalOk = col.first < x && col.second > x;
        bool horizontalOk = row.first < y && row.second > y;

        if (verticalOk && horizontalOk) ++count;
    }
    return count;
}

}  // namespace

CountCoveredBuildingsSolution::CountCoveredBuildingsSolution() {
    setMetaInfo({.id = 3531,
                 .title = "Count Covered Buildings",
                 .url = "https://leetcode.com/problems/count-covered-buildings/"});
    registerStrategy({.name = "HashGroupMinMax",
                      .expected = "Accepted",
                      .time_complexity = "O(B)",
                      .space_complexity = "O(B)",
                      .tags = {"Hash Table", "Array"}},
                     countCoveredBuildingsImpl);
}

int CountCoveredBuildingsSolution::countCoveredBuildings(
    int n, std::vector<std::vector<int>>& buildings) {
    return getSolution()(n, buildings);
}

}  // namespace leetcode::problem_3531
