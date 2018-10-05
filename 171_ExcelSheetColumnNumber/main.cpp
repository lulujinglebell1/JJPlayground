//
//  main.cpp
//  171_ExcelSheetColumnNumber
//
//  Created by Jane Jane on 9/20/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>  //find n2
#include <assert.h>
#include <math.h>  //
#include <set>  //

using namespace std;
/*
 Given a column title as appear in an Excel sheet, return its corresponding column number.
 
 For example:
 
 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28
 ...
 Example 1:
 
 Input: "A"
 Output: 1
 Example 2:
 
 Input: "AB"
 Output: 28
 Example 3:
 
 Input: "ZY"
 Output: 701
 */
int time26 (int timeNum){
    int result = 1;
    if (timeNum == 0){
        return 1;
    }else{
        for (int i = 1; i <= timeNum; i++){
            result = result * 26;
        }
    }
    return result;
}

int titleToNumber(string s) {
    int lenS = (int) s.length();
    char curChar;
    int charD;
    int result = 0;
    int time = 0;
    
    for (int i = (lenS - 1); i >= 0; i--){
        curChar = s[i];
        charD = (int)curChar - 64;
        result = result + charD * time26(time);
        time++;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    string input = "AA";
    assert(titleToNumber(input) == 27);
    return 0;
}
