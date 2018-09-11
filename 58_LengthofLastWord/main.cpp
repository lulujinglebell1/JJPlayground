//
//  main.cpp
//  58_LengthofLastWord
//
//  Created by Jane Jane on 9/8/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

/*
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 
 Note: A word is defined as a character sequence consists of non-space characters only.
 
 Example:
 
 Input: "Hello World"
 Output: 5
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int sizeString = (int) s.length();
        int result = 0;
        
        for (int i = sizeString - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                return result;
            } else {
                result++;
            }
        }
        return sizeString;
    }
};
 
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    string stringInput = "Hello World";
    assert(s.lengthOfLastWord(stringInput) == 5);
    return 0;
}
