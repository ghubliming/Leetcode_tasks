//
//  simple_test.cpp
//  Leetcode_task
//
//  Created by liu on 09.09.24.
//

#include <iostream>  // Use iostream for std::cout

class Solution {
public:
    int cal(int num) {
        int m = num % 1000;
        return m;
    }
};

int main () {
    Solution sol;
    int num = 101;
    int result = sol.cal(num);  // Pass the 'num' variable to the function
    std::cout << result << std::endl;  // Output the result of the function
    
}
