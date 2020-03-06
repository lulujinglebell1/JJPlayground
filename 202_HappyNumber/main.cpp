//
//  main.cpp
//  202_HappyNumber
//
//  Created by Jane Jane on 3/5/20.
//  Copyright © 2020 Jane Jane. All rights reserved.
//

#include <iostream>
#include <assert.h>
/*
 Write an algorithm to determine if a number is "happy".
 
 A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 
 Example:
 
 Input: 19
 Output: true
 Explanation:
 12 + 92 = 82
 82 + 22 = 68
 62 + 82 = 100
 12 + 02 + 02 = 1
 
 Input: 2
 Output: true
 Explanation:
 22 = 4
 42 = 16
 12 + 62 = 37
 32 + 72 = 9 + 49 = 58
 */

class Solution {
public:
    bool isHappy(int n) {
        int input = n;
        int result = n;
        
        while (result != 1) {
            n = result;
            result = 0;
            while (n/10 != 0 || n%10 !=0) {
                result = result + (n%10)*(n%10);
                n = n/10;
            }
            if (result == input * input) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    assert (s.isHappy(19) == true);
    assert (s.isHappy(2) == false);
    return 0;
}
