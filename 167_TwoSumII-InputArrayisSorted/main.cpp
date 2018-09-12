//
//  main.cpp
//  167_TwoSumII-InputArrayisSorted
//
//  Created by Jane Jane on 9/11/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>  //find n2
#include <assert.h>
#include <math.h>  //
#include <set>  //

using namespace std;

/*
 
 Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
 
 Note:
 
 Your returned answers (both index1 and index2) are not zero-based.
 You may assume that each input would have exactly one solution and you may not use the same element twice.
 Example:
 
 Input: numbers = [2,7,11,15], target = 9
 Output: [1,2]
 Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftIndex = 0;
        int rightIndex = (int)numbers.size()-1;
        int sum = 0;
        vector<int> resultIndex;
        
        while(rightIndex > leftIndex) {
            sum = numbers[leftIndex] + numbers[rightIndex];
            if (sum == target) {
                resultIndex.push_back(leftIndex+1);
                resultIndex.push_back(rightIndex+1);
                break;
            }
            if(sum > target) {
                rightIndex--;
            } else {
                leftIndex++;
            }
        }
        return resultIndex;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
