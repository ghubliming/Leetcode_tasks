#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;  // Track the farthest point we can reach
        
        cout << "Processing array: ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        
        for (int i = 0; i < n; i++) {
            cout << "At index " << i << ", value: " << nums[i] << endl;
            cout << "MaxReach: " << maxReach << endl;

            if (i > maxReach) {
                cout << "Failed to reach index " << i << ", returning false." << endl;
                return false; // If we're at a point we can't reach, return false
            }

            // Update the farthest point we can reach
            maxReach = max(maxReach, i + nums[i]);
            cout << "Updated MaxReach: " << maxReach << endl;

            // If we can reach the last index, return true
            if (maxReach >= n - 1) {
                cout << "Can reach the last index from index " << i << ", returning true." << endl;
                return true;
            }
        }
        
        cout << "Exiting loop, can't reach the last index, returning false." << endl;
        return false;  // In case we exit the loop without reaching the end
    }
};

int main() {
    Solution sol;
    
    // Test cases
    vector<vector<int>> testCases = {
        {2, 3, 1, 1, 4},   // Expected: true
        {3, 2, 1, 0, 4},   // Expected: false
        {0},               // Expected: true (since you're already at the end)
        {2, 0},            // Expected: true
        {1, 2, 3, 0, 0, 1}, // Expected: true
        {1, 2, 3, 0, 0, 0, 1}  // Expected: false
    };
    
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i + 1 << ":" << endl;
        bool result = sol.canJump(testCases[i]);
        cout << "Result: " << (result ? "true" : "false") << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}
