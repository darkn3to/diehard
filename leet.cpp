#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string window = "";
    int minLen=INT_MAX;
    unordered_map<char, int> have, need;
    bool check(unordered_map<char, int> &m) {
        for (auto it : m) {
            if (it.second == 0) return false;
        }
        return true;
    }
    
    void create(int &l, int &r, string &s) {
    while (check(have)) {
        if (r-l+1<minLen) {
            minLen=r-l+1;
            if (minLen <= s.size()) {
                window=s.substr(l, minLen);
            }
        }
        if (need.find(s[l]) != need.end()) have[s[l]]--;
        l++;
    }
}
    
    string minWindow(string &s, string &t) {
        if (s.size()<t.size()) return "";
        int l = 0, r = 0;
        for (auto it:t) need[it]++;
        window = s;
        while (r<s.size()) {
            if (check(have)) create(l, r, s);
            if (need.find(s[r]) != need.end()) have[s[r]]++;
            r++;
        }
        return window;
    }
};
int main() {
    Solution solution;

    // Example usage:
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = solution.minWindow(s, t);
    std::cout << "Minimum window substring: " << result << std::endl;

    return 0;
}