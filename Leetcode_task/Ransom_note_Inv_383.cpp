#include <iostream>
#include <unordered_map>
#include <string>
#include <utility> // For std::pair

class Solution {
public:
    std::pair<bool, std::unordered_map<char, int>> canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> dictionary;

        // Initialize the hashmap
        for (char c : magazine) {
            if (dictionary.find(c) == dictionary.end()) {
                dictionary[c] = 1; // If character not found, initialize with 1
                std::cout << "Added: '" << c << "' with count: " << dictionary[c] << std::endl;
            } else {
                dictionary[c]++;
                std::cout << "Updated: '" << c << "' to count: " << dictionary[c] << std::endl;
            }
        }

        // Check if we can construct the ransom note
        std::cout << std::endl << "Ransom Check begins" << std::endl;
        for (char c : ransomNote) {
            if (dictionary.find(c) != dictionary.end() && dictionary[c] > 0) {
                dictionary[c]--;
                std::cout << "Used: '" << c << "' remaining count: " << dictionary[c] << std::endl;
            } else {
                std::cout << "Cannot use: '" << c << "' - not enough characters." << std::endl;
                return {false, dictionary}; // Return false with current dictionary
            }
        }

        return {true, dictionary}; // Return true with final dictionary
    }
};

