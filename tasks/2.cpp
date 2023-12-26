#include <iostream>
#include <vector>
#include <cmath>

bool findIndexValueDiff(const std::vector<int>& nums, int indexDiff, int valueDiff) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size() && j <= i + indexDiff; j++) {
            if (std::abs(nums[i] - nums[j]) <= valueDiff) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector<int> nums = { 1, 3, 5, 7, 9 };
    int indexDiff = 3;
    int valueDiff = 3;

    bool result = findIndexValueDiff(nums, indexDiff, valueDiff);

    if (result) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }

    return 0;
}