#include <iostream>
#include <queue>

class MedianFinder {
private:
    std::priority_queue<int> maxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else {
            return maxHeap.top();
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(2);
    mf.addNum(3);
    std::cout << mf.findMedian() << std::endl;
    mf.addNum(4);
    std::cout << mf.findMedian() << std::endl;
    return 0;
}