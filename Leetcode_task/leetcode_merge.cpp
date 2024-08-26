//
//  main.cpp
//  Leetcode_task
//
//  Created by liu on 26.08.24.
//


#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Append elements from nums2 to nums1
        for (int j = 0, i = m; j < n; j++) {
            nums1[i] = nums2[j];
            i++;
        }
        // Sort the entire nums1 array
        sort(nums1.begin(), nums1.end());
    }
};

int main() {
    // Input
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    // Create a Solution object and call the merge function
    Solution sol;
    sol.merge(nums1, m, nums2, n);

    // Output
    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


