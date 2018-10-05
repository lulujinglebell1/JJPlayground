//
//  main.cpp
//  5_LongestPalindromicSubstring
//
//  Created by Jane Jane on 10/3/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
using namespace std;

/*
 Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 
 Example 1:
 
 Input: "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 Example 2:
 
 Input: "cbbd"
 Output: "bb"
 
 
 **************************
 Need to make used of DP
 the current dp[i][j] will depend on if dp[i+1][j-1] is palidrome or not
 also need to make sure the dp[x][x] is not acccessing the invalid address
 
 dp1
 dp2  dp3
 dp4  dp5  dp6
 dp7  dp8  dp9  dp10
 dp11 dp12 dp13 dp14 dp15
 
 
 outputString = s.substr (startIndex, charCount)
 **************************
 */

string longestPalindrome(string s) {
    string outPutString;
    unsigned int sizeofString = (unsigned int) s.length();
    int curLong = 0;
    if (sizeofString == 0) {
        return s;
    }
    bool dp[sizeofString][sizeofString];
    
    for (int j = 0; j < s.length(); j++) { //right
        for (int i = 0; i <= j; i++) { //left
            //dp[i][j] i&j with same index, dp[i][j] is ture  ==> do "d" will output "d"
            //dp[i][j] j-i=1, and s[i] == s[j], dp[i][j] is true ==>so "dd" will output "dd"
            dp[i][j] = (s[i]==s[j]) && ((j-i < 2) || (dp[i+1][j-1]));
            if (dp[i][j] == true) {
                if (j - i + 1 > curLong) {
                    curLong = j - i + 1;
                    outPutString = s.substr(i,j-i+1);
                }
            }
        }
    }
    
    return outPutString;
}

/*
string longestPalindrome(string s) {
    vector<vector<bool>> isPalindrom(s.size(), vector<bool>(s.size(), false));
    string result;
    
    for (int j = 0; j < s.length(); j++) { //right
        for (int i = 0; i <= j; i++) { //left
            if (s[i] == s[j] && (j - i < 2 || isPalindrom[i+1][j-1])) {
                isPalindrom[i][j] = true;
                if (j - i + 1 > result.size()){
                    result = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return result;
    
}
 */
/*
string longestPalindrome(string s) {
    vector<vector<bool>> isPalindrom(s.size(), vector<bool>(s.size(), false));
    string result;
    for (int i = s.size() - 1; i >= 0; i--){ //left
        for (int j = i; j < s.size(); j++){ //right
            if (s[i] == s[j] && (j - i < 2 || isPalindrom[i+1][j-1])){
                isPalindrom[i][j] = true;
                if (j - i + 1 > result.size()){
                    result = s.substr(i, j - i + 1);
                }
            }
        }
    }
    
    return result;
}
*/

int main (int argc, const char * argv[]) {
    string inputString = "babad";
    assert (longestPalindrome(inputString) == "bab");
    return 0;
}
