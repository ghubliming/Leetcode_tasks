#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
private:
    // Method to compute the next number (sum of squares of digits)
    int nextNumber(int n) {
        int newNumber = 0;
        while (n != 0) {
            int num = n % 10;
            newNumber += num * num;
            n = n / 10;
        }
        return newNumber;
    }

public:
    // Method 1: Using a set to detect cycles
    bool isHappy(int n) {
        unordered_set<int> set;
        cout << "Sequence (Method 1): " << n;
        while (n != 1 && !set.count(n)) {
            set.insert(n);
            n = nextNumber(n);
            cout << " -> " << n;  // Print the next number in the sequence
        }
        cout << endl;
        return n == 1;
    }

    // Method 2: Using Floyd's Cycle Detection (Tortoise and Hare)
    bool isHappy2(int n) {
        int slowPointer = n;
        int fastPointer = nextNumber(n);

        cout << "Sequence (Method 2): " << slowPointer;
        while (fastPointer != 1 && fastPointer != slowPointer) {
            slowPointer = nextNumber(slowPointer);
            fastPointer = nextNumber(nextNumber(fastPointer));
            cout << " -> " << slowPointer;  // Print the slowPointer's sequence
        }
        cout << endl;
        return fastPointer == 1;
    }
};

// Main function to test both methods
int main() {
    Solution solution;
    int number;

    // Input a number to check if it's happy
    cout << "Enter a number: ";
    cin >> number;

    // Test the first method using a set
    if (solution.isHappy(number)) {
        cout << "Method 1: " << number << " is a happy number!" << endl;
    } else {
        cout << "Method 1: " << number << " is not a happy number." << endl;
    }

    // Test the second method using Floyd's Cycle Detection
    if (solution.isHappy2(number)) {
        cout << "Method 2: " << number << " is a happy number!" << endl;
    } else {
        cout << "Method 2: " << number << " is not a happy number." << endl;
    }

    return 0;
}
