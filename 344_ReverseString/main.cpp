//
//  main.cpp
//  344_ReverseString
//
//  Created by JJ  on 3/8/20.
//  Copyright © 2020 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/*
 Write a function that reverses a string. The input string is given as an array of characters char[].

 Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

 You may assume all the characters consist of printable ascii characters.

  

 Example 1:

 Input: ["h","e","l","l","o"]
 Output: ["o","l","l","e","h"]
 Example 2:

 Input: ["H","a","n","n","a","h"]
 Output: ["h","a","n","n","a","H"]
 */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int frontIndex = 0;
        int backIndex = (int) s.size() - 1;
        int temp;
        
        while (frontIndex < backIndex) {
            temp = s[frontIndex];
            s[frontIndex] = s[backIndex];
            s[backIndex] = temp;
            frontIndex++;
            backIndex--;
        }
        return;
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    int index = 0;
    vector<char> input = {'H', 'e', 'l', 'l', 'o'};
    s.reverseString(input);
    
    while (index < input.size()) {
        printf("%c", input[index]);
        index++;
    }
    return 0;
}
