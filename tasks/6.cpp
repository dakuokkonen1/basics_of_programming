#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }

    std::vector<int> leftProfit(n, 0);
    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
        minPrice = std::min(minPrice, prices[i]);
        leftProfit[i] = std::max(leftProfit[i - 1], prices[i] - minPrice);
    }

    std::vector<int> rightProfit(n, 0);
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        maxPrice = std::max(maxPrice, prices[i]);
        rightProfit[i] = std::max(rightProfit[i + 1], maxPrice - prices[i]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; ++i) {
        maxProfit = std::max(maxProfit, leftProfit[i] + rightProfit[i]);
    }

    return maxProfit;
}

int main() {
    std::vector<int> prices = { 3, 2, 1, 0, 0, 3, 1, 4 };
    std::cout << "The maximal profit: " << maxProfit(prices) << std::endl;
    return 0;
}
