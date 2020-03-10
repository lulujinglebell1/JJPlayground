//
//  main.cpp
//  6_ZigZagConversion
//
//  Created by JJ  on 3/9/20.
//  Copyright © 2020 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"

 Write the code that will take a string and make this conrversion given a number of rows:

 string convert(string s, int numRows);
 Example 1:

 Input: s = "PAYPALISHIRING", numRows = 3
 Output: "PAHNAPLSIIGYIR"
 Example 2:

 Input: s = "PAYPALISHIRING", numRows = 4
 Output: "PINALSIGYAHRPI"
 Explanation:

 P     I    N
 A   L S  I G
 Y A   H R
 P     I
 */

class Solution {
public:
    string convert(string s, int numRows) {
        string output;
        //the row number not only depends on the input numRows, but also depends on how many char in the input string
        int finalNumOfRow = 0;
        finalNumOfRow = min (numRows, (int)s.size());
        
        vector<string> stringRow(finalNumOfRow);
        int charIndex = 0;
        int curRow = 0;
        char curChar;
        int upOrDown = 1;
        
        //handle special case where only need to output one row
        if (numRows == 1) {
            return s;
        }
        curChar = s[0];
        while(charIndex < s.size()){
            //when there are still char need to handle, append the char to the correct row first
            curChar = s[charIndex];
            stringRow[curRow]+=curChar;
            //manage the next row number, move up or move down
            if (curRow == 0) {
                upOrDown = 1;
            }
            if (curRow == finalNumOfRow - 1) {
                upOrDown = -1;
            }
            curRow = curRow + upOrDown;
            //move to the next char
            charIndex++;

        }
        
        //append all the row together to output
        curRow = 0;
        while (curRow < finalNumOfRow) {
            output += stringRow[curRow];
            curRow++;
        }
        return output;
    }
};


int main(int argc, const char * argv[]) {
    Solution s;
    string input = "PAYPALISHIRING";
    assert(s.convert(input, 3)=="PAHNAPLSIIGYIR");
    return 0;
}
