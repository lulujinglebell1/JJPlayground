//
//  main.cpp
//  10_RegularExpressionMatching
//
//  Created by Jane Jane on 8/1/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

/*
 
 Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 The matching should cover the entire input string (not partial).
 
 Note:
 
 s could be empty and contains only lowercase letters a-z.
 p could be empty and contains only lowercase letters a-z, and characters like . or *.
 Example 1:
 
 Input:
 s = "aa"
 p = "a"
 Output: false
 Explanation: "a" does not match the entire string "aa".
 Example 2:
 
 Input:
 s = "aa"
 p = "a*"
 Output: true
 Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 Example 3:
 
 Input:
 s = "ab"
 p = ".*"
 Output: true
 Explanation: ".*" means "zero or more (*) of any character (.)".
 Example 4:
 
 Input:
 s = "aab"
 p = "c*a*b"
 Output: true
 Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
 Example 5:
 
 Input:
 s = "mississippi"
 p = "mis*is*p*."
 Output: false
*/



#include <iostream>
#include <string.h>
#include <assert.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        unsigned long sizePattern = p.size();
        unsigned long sizeInput = s.size();
        
        int i = 0, j = 0;
        for (; (i < sizePattern) && (j < sizeInput); i++) {
            char pCharCurr = p[i];
            if ((i+1 != sizePattern) &&
                p[i+1] == '*') {
                for (; j < sizeInput; j++) {
                    if (!isCharMatched(s[j], pCharCurr)) {
                        break;
                    }
                }
                i++;
            } else {
                if (isCharMatched(s[j], pCharCurr)) {
                    j++;
                } else {
                    return false;
                }
            }
        }

        if ((i == sizePattern) &&
            (j == sizeInput)) {
            return true;
        } else {
            return false;
        }
    }
    
private:
    bool isCharMatched(char cS, char cP) {
        if (cS == cP || cP == '.') {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    
    assert(false == s.isMatch("aa", "a"));
    assert(s.isMatch("aa", "a*"));
    assert(s.isMatch("ab", ".*"));
    assert(s.isMatch("aab", "c*a*b"));
    assert(false == s.isMatch("mississippi", "mis*is*p*."));
    assert(s.isMatch("aaa", "a*a"));


    return 0;
}
