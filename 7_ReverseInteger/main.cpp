//
//  main.cpp
//  7_ReverseInteger
//
//  Created by Jane Jane on 3/5/20.
//  Copyright © 2020 Jane Jane. All rights reserved.
//

#include <iostream>
#include <assert.h>
/*
 Given a 32-bit signed integer, reverse digits of an integer.
 
 Example 1:
 
 Input: 123
 Output: 321
 Example 2:
 
 Input: -123
 Output: -321
 Example 3:
 
 Input: 120
 Output: 21
 */

class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        int finalResult;
        int signOfInterger = 1;
        int lastInteger;
        
        /*
         integer value range: (2 byte)-32,768 to 32,767 or (4byte) -2,147,483,648 to 2,147,483,647
         signed integer overflow: -2147483648 * -1 cannot be represented in type 'int' (solution.cpp)
         */
        if (x < 0) {
            if (x == -2147483648) {
                return 0;
            }
            signOfInterger = -1;
            x = x * signOfInterger;
        }
  
        while ((x/10 != 0) || (x%10 != 0)) {
            lastInteger = x % 10;
            result = result * 10 + lastInteger;
            x = x/10;
        }

        result = result * signOfInterger;
        
        /*integer value range: (2 byte)-32,768 to 32,767 or (4byte) -2,147,483,648 to 2,147,483,647
         to avoid over flow when reverse the integer, we need to make result as long long
         then check when cast back to int, the result is equal to the final result
         if not, then we need to return 0;
         */
        finalResult = (int)result;
        if(finalResult == result) {
            return result;
        } else {
            return 0;
        }
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    assert (s.reverse(123) == 321);
    assert (s.reverse(-123) == -321);
    assert (s.reverse(120) == 21);
    assert (s.reverse(1) == 1);
    return 0;
}
