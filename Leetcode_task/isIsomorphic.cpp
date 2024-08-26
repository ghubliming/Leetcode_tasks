#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;  // If strings are of different lengths, return false.

        int mapS[256] = {0};  // Maps from s to t
        int mapT[256] = {0};  // Maps from t to s

        // Loop through each character of both strings.
        for (size_t i = 0; i < s.size(); ++i) {
            if (mapS[s[i]] == 0 && mapT[t[i]] == 0) {
                // If no mapping exists, create a new one.
                mapS[s[i]] = t[i];
                mapT[t[i]] = s[i];
            }
            else if (mapS[s[i]] != t[i] || mapT[t[i]] != s[i]) {
                // If a mapping exists but it doesn't match, print the maps and return false.
                printFullMappings(mapS, mapT);
                return false;
            }
        }

        // If mappings are consistent, print the maps and return true.
        printFullMappings(mapS, mapT);
        return true;
    }

    // Helper function to print all mappings, including empty ones.
    void printFullMappings(int mapS[], int mapT[]) {
        cout << "\n--- Full Mapping from s -> t ---\n";
        for (int i = 0; i < 256; ++i) {
            cout << "'" << char(i) << "' -> '" << char(mapS[i]) << "' (" << mapS[i] << ")\n";
        }

        cout << "\n--- Full Mapping from t -> s ---\n";
        for (int i = 0; i < 256; ++i) {
            cout << "'" << char(i) << "' -> '" << char(mapT[i]) << "' (" << mapT[i] << ")\n";
        }
    }
};

int main() {
    // Input strings for checking if they are isomorphic.
    string s, t;

    cout << "Enter the first string: ";
    cin >> s;

    cout << "Enter the second string: ";
    cin >> t;

    // Create an instance of the Solution class.
    Solution solution;

    // Check if the strings are isomorphic and print the result.
    bool result = solution.isIsomorphic(s, t);

    if (result) {
        cout << "\nThe strings '" << s << "' and '" << t << "' are isomorphic." << endl;
    } else {
        cout << "\nThe strings '" << s << "' and '" << t << "' are NOT isomorphic." << endl;
    }

    return 0;
}
