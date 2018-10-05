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
#include <vector>

using namespace std;

class Solution {
public:
    /*
     bp[s.size()+1][s.size()+1]
     bp[0][0] = true
     
     if (isCharMatched(s[i], p[j]))
        bp[i][j] = bp[i-1][j-1]
     else if (p[j] == '*')
        // zero occurance
        bp[i][j] = bp[i][j-2]
        // multiple occrance
        bp[i][j] = bp[i-1][j]
     else
        bp[i][j] = false
     */
    bool isMatch(string s, string p) {
        unsigned long dpLenghtS = s.size() + 1;
        unsigned long dpLenghtP = p.size() + 1;
        vector<vector<bool>> dp(dpLenghtS, vector<bool>(dpLenghtP, false));
        
        dp[0][0] = true;
        
        // initialization
        // Take care of a*b*c, a*
        for (int j = 1; j < dp[0].size(); j++) {
            if (p[j] == '*') {
                dp[0][j+1] = dp[0][j-1];
            }
        }
        
        for (int i = 1; i < dpLenghtS; i++) {
            for (int j = 1; j < dpLenghtP; j++) {
                if (isCharMatched(s[i-1], p[j-1])) {
                    // if match
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    if (isCharMatched(s[i-1], p[j-2])) {
                        // single or multiple occurance
                        dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-2];
                    } else {
                        // zero occurance
                        dp[i][j] = dp[i][j-2];
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }
        
        //printResult(s, p, dp);
        return dp[dpLenghtS-1][dpLenghtP-1];
    }
    
private:
    void printResult(string s, string p, vector<vector<bool>> result) {
        string printS = 'X' + s;
        string printP = 'X' + p;
        cout << '\t';
        for (int i = 0; i < printP.size(); i++) {
            cout << printP[i] << '\t';
        }
        cout << endl;
        for (int i = 0; i < printS.size(); i++) {
            cout << printS[i] << '\t';
            for (int j = 0; j < printP.size(); j++) {
                cout << (result[i][j] ? 'T' : 'F') << '\t';
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    
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
    assert(s.isMatch("aaa", "ab*a*c*a"));

    return 0;
}
