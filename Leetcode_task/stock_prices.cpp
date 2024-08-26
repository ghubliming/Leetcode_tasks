//
//  stock_prices.cpp
//  Leetcode_task
//
//  Created by liu on 06.09.24.
//

#include <iostream>
#include <vector>
#include <algorithm>  // For std::min and std::max

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty()) return 0;  // Handle empty input case
        
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            // Calculate profit if we sold at prices[i]
            int profit = prices[i] - minPrice;
            maxProfit = std::max(maxProfit, profit);
            
            // Update the minimum price if a lower price is found
            minPrice = std::min(minPrice, prices[i]);
            std::cout << prices[i] << " ," << maxProfit << " ," << minPrice << std::endl;

        }
        
        return maxProfit;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: Regular test case
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    std::cout << "Max Profit (Test Case 1): " << solution.maxProfit(prices1) << std::endl;


    // Test case 2: Prices decreasing, no profit can be made
    std::vector<int> prices2 = {7, 6, 4, 3, 1, 999, 0, 999, 1000};
    std::cout << "Max Profit (Test Case 2): " << solution.maxProfit(prices2) << std::endl;


    // Test case 3: Prices increasing, max profit can be made by buying on the first day and selling on the last
    std::vector<int> prices3 = {1, 2, 3, 4, 5};
    std::cout << "Max Profit (Test Case 3): " << solution.maxProfit(prices3) << std::endl;


    return 0;
}
