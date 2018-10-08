//
//  main.cpp
//  42_TrappingRainWater
//
//  Created by Jane Jane on 10/6/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>
/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 
 
 The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 
 Example:
                       *
               *       * *   *
           *   * *   * * * * * *
 Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 Output: 6
 */

int trap(vector<int>& height) {
    int leftIndex = 0;
    int rightIndex = height.size() - 1;
    int leftMax = 0;
    int rightMax = 0;
    int result = 0;
    
    while (leftIndex < rightIndex) {
        if (height[leftIndex] < height[rightIndex]) {
            leftMax = max (leftMax, height[leftIndex]);
            result = result + (leftMax - height[leftIndex]);
            leftIndex++;
        } else {
            rightMax = max (rightMax, height[rightIndex]);
            result = result + (rightMax - height[rightIndex]);
            rightIndex--;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {

    return 0;
}
