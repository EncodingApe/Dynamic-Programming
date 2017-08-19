#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

// Given a string, your task is to count how many palindromic(回文) substrings in this string.
// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
// 从中间向两侧

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            countSubstrings(s, i, i, count);    // palindromic length is even
            countSubstrings(s, i, i+1, count);  // palindromic length is odd
        }
        return count;
    }

    void countSubstrings(string s, int lindex, int rindex, int &count) {
        for(; lindex >= 0 && rindex < s.length(); lindex--, rindex++) {
            if(s[lindex] != s[rindex]) break;
            count++;
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    cout << s.countSubstrings("aaa");
    return 0;
}
