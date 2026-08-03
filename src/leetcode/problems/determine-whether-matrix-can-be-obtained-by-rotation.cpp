#include "leetcode/problems/determine-whether-matrix-can-be-obtained-by-rotation.h"

#include <vector>

namespace leetcode::problem_1886 {

namespace {

bool equalMatrices(const std::vector<std::vector<int>>& a,
                   const std::vector<std::vector<int>>& b) {
    int n = static_cast<int>(a.size());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool findRotationImpl(std::vector<std::vector<int>>& mat,
                      std::vector<std::vector<int>>& target) {
    int n = static_cast<int>(mat.size());

    std::vector<std::vector<int>> current = mat;
    for (int k = 0; k < 4; ++k) {
        if (equalMatrices(current, target)) {
            return true;
        }
        // Rotate current by 90 degrees clockwise.
        std::vector<std::vector<int>> rotated(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rotated[j][n - 1 - i] = current[i][j];
            }
        }
        current = std::move(rotated);
    }
    return false;
}

}  // namespace

DetermineWhetherMatrixCanBeObtainedByRotationSolution::
    DetermineWhetherMatrixCanBeObtainedByRotationSolution() {
    setMetaInfo({.id = 1886,
                 .title = "Determine Whether Matrix Can Be Obtained By Rotation",
                 .url = "https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/"});
    registerStrategy({.name = "simulate-four-rotations",
                      .expected = "Accepted",
                      .time_complexity = "O(n^2)",
                      .space_complexity = "O(n^2)",
                      .tags = {"Array", "Matrix"}},
                     findRotationImpl);
}

bool DetermineWhetherMatrixCanBeObtainedByRotationSolution::findRotation(
    std::vector<std::vector<int>>& mat, std::vector<std::vector<int>>& target) {
    return getSolution()(mat, target);
}

}  // namespace leetcode::problem_1886
