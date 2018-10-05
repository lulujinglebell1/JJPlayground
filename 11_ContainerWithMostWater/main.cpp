//
//  main.cpp
//  11_ContainerWithMostWater
//
//  Created by Jane Jane on 10/4/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

/*
 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 
 Note: You may not slant the container and n is at least 2.
 
 The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
 
 */
int maxArea (vector<int>& height) {
    int width;
    int high;
    int left = 0;
    unsigned int right = (unsigned int) height.size() - 1;
    int volume = 0;
    
    while (right - left >= 1) {
        width = right - left;
        high = min (height[left], height[right]);
        volume = max (volume, width * high);
        
        if (height[left] < height[right])
        {
            left++;
        } else {
            right--;
        }
    }
    return volume;
}

int main (int argc, const char * argv[]) {
    vector<int> inputVector = {1,8,6,2,5,4,8,3,7};
    assert (maxArea(inputVector) == 49);
    
    return 0;
}
