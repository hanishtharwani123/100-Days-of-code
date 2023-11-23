// 87. Find Median from Data Stream
#include <queue>
#include <vector>

class MedianFinder {
public:
    // Constructor
    MedianFinder() {}

    // Add a number to the data stream
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps to ensure the size difference is at most 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Find the median of all elements so far
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }

private:
    std::priority_queue<int> maxHeap;  // Max heap for the smaller half
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;  // Min heap for the larger half
};

int main() {
    // Example usage
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    double result1 = medianFinder.findMedian();  // 1.5
    medianFinder.addNum(3);
    double result2 = medianFinder.findMedian();  // 2.0

    return 0;
}
