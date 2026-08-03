#ifndef LEETCODE_PROBLEMS_GENERATE_TAG_FOR_VIDEO_CAPTION_H__
#define LEETCODE_PROBLEMS_GENERATE_TAG_FOR_VIDEO_CAPTION_H__

#include <functional>
#include <string>

#include "leetcode/core.h"

namespace leetcode {
namespace problem_3582 {

using Func = std::function<std::string(std::string)>;

class GenerateTagForVideoCaptionSolution
    : public SolutionBase<Func> {
 public:
  GenerateTagForVideoCaptionSolution();

  std::string generateTag(std::string caption);
};

}  // namespace problem_3582
}  // namespace leetcode

#endif  // LEETCODE_PROBLEMS_GENERATE_TAG_FOR_VIDEO_CAPTION_H__
