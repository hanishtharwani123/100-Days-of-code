// 1. Two Sum

#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> numToIndex;

  for (int i = 0; i < nums.size(); ++i) {
    if (numToIndex.count(target - nums[i])) {
      return { numToIndex[target - nums[i]], i };
    }

    numToIndex[nums[i]] = i;
  }

  return {};
}

int main() {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  std::vector<int> result = twoSum(nums, target);

  if (!result.empty()) {
    std::cout << "Indices: " << result[0] << ", " << result[1] << std::endl;
    std::cout << "Numbers: " << nums[result[0]] << ", " << nums[result[1]] << std::endl;
  } else {
    std::cout << "No solution found." << std::endl;
  }

  return 0;
}
