#include <iostream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Maps to track the last seen index of pattern characters and words in string s
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(s);  // Breaks the string 's' into words
        int i = 0, n = pattern.size();  // i keeps track of the index of words, n is the size of the pattern

        // Loop through each word in the input string 's'
        for (string word; in >> word; ++i) {
            // Print the current step
            cout << "\nStep " << i + 1 << ":\n";
            cout << "Processing word: \"" << word << "\"\n";
            cout << "Current pattern character: '" << pattern[i] << "'\n";

            // Print the current map states before updating
            cout << "Current p2i (pattern to index map): ";
            printMap(p2i);
            cout << "Current w2i (word to index map): ";
            printMap(w2i);

            // If we run out of pattern characters or there's a mismatch between the pattern and word mapping
            if (i == n || p2i[pattern[i]] != w2i[word]) {
                cout << "Mismatch or pattern length exceeded. Returning false.\n";
                return false;  // Mismatch found, return false
            }

            // Map the current character and word to the index i + 1
            p2i[pattern[i]] = w2i[word] = i + 1;

            // Print the updated map states
            cout << "Updated p2i (pattern to index map): ";
            printMap(p2i);
            cout << "Updated w2i (word to index map): ";
            printMap(w2i);
        }
        // At the end, check if we've processed exactly the number of words as the pattern length
        cout << "\nProcessing complete.\n";
        return i == n;
    }

private:
    // Helper function to print the contents of a map (for both pattern and word maps)
    template <typename T, typename U>
    void printMap(const map<T, U>& m) {
        cout << "{ ";
        for (const auto& pair : m) {
            cout << pair.first << ": " << pair.second << " ";
        }
        cout << "}\n";
    }
};

int main() {
    // Sample input
    string pattern = "abca";
    string s = "dog ct cat dog";

    // Create a solution object and call the function
    Solution solution;
    bool result = solution.wordPattern(pattern, s);

    // Output result
    if (result) {
        cout << "\nThe string follows the pattern." << endl;
    } else {
        cout << "\nThe string does not follow the pattern." << endl;
    }

    return 0;
}
