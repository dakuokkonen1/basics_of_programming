#include <iostream>
#include <vector>
using namespace std;

int maximalRectangleArea(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j]++;
            }
            else {
                heights[j] = 0;
            }
        }
        vector<int> left(cols, 0);
        vector<int> right(cols, cols);
        vector<int> stack;
        for (int j = 0; j < cols; j++) {
            while (!stack.empty() && heights[stack.back()] >= heights[j]) {
                stack.pop_back();
            }
            left[j] = stack.empty() ? -1 : stack.back();
            stack.push_back(j);
        }
        stack.clear();
        for (int j = cols - 1; j >= 0; j--) {
            while (!stack.empty() && heights[stack.back()] >= heights[j]) {
                stack.pop_back();
            }
            right[j] = stack.empty() ? cols : stack.back();
            stack.push_back(j);
        }
        for (int j = 0; j < cols; j++) {
            maxArea = max(maxArea, heights[j] * (right[j] - left[j] - 1));
        }
    }
    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'0', '0', '1', '0', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << "The maximal area of a rectangle is: " << maximalRectangleArea(matrix) << endl;
    return 0;
}