// 34. Merge Intervals
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    static bool compareStart(const std::vector<int>& interval1, const std::vector<int>& interval2) {
        return interval1[0] < interval2[0];
    }

    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), compareStart);

        std::vector<std::vector<int>> result;
        for (const auto& interval : intervals) {
            if (result.empty() || interval[0] > result.back()[1]) {
                result.push_back(interval);
            } else {
                result.back()[1] = std::max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};

int main() {
    std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    Solution solution;
    std::vector<std::vector<int>> mergedIntervals = solution.merge(intervals);

    for (const auto& interval : mergedIntervals) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}
