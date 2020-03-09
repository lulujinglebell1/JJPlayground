//
//  main.cpp
//  283_MoveZeroes
//
//  Created by JJ  on 3/8/20.
//  Copyright © 2020 Jane Jane. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

 Example:

 Input: [0,1,0,3,12]
 Output: [1,3,12,0,0]
 Note:

 You must do this in-place without making a copy of the array.
 Minimize the total number of operations.
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int firstIndex = 0;
        int secondIndex = 0;
        while (firstIndex < nums.size()) {
            if (nums[firstIndex] != 0) {
                firstIndex++;
            }else{
                secondIndex = firstIndex + 1;
                while ((secondIndex <  nums.size()) &&
                       (nums[secondIndex] == 0)){
                    secondIndex++;
                }
                if (secondIndex == nums.size()) {
                    return;
                }
                nums[firstIndex] = nums[secondIndex];
                nums[secondIndex] = 0;
                firstIndex ++;
            }
        }
        return;
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    int vectorIndex = 0;
    vector<int> input = {0,1,0,3,12};
    s.moveZeroes(input);
    
    while (vectorIndex < input.size()) {
        printf(" %d", input[vectorIndex]);
        vectorIndex++;
    }
    return 0;
}
