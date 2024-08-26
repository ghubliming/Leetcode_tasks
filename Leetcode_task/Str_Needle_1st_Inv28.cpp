#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.length() - needle.length(); i++) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    //int ans = -99;	
    string Haystack = "xcxxxxxsadbutsad", Needle = "sad";
    int ans = sol.strStr(Haystack, Needle);
    cout << ans << endl;
    return 0; //0 is success, 1 is for error
}
