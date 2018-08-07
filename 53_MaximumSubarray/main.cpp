//
//  main.cpp
//  53_MaximumSubarray
//
//  Created by Jane Jane on 8/7/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

/*
 Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 
 Example:
 
 Input: [-2,1,-3,4,-1,2,1,-5,4],
 Output: 6
 Explanation: [4,-1,2,1] has the largest sum = 6.
 Follow up:
 
 If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

//Input: [-2,1,-3,4,-1,2,1,-5,4],
//dp[0, 1, 0, 4, 3, 5, 6, ]

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // unsigned int can represent max 2^31, but signed int can only represent max 2^30. nums.size will return a unsigned int, so we need to declear numsLength as unsigned int
        unsigned long numsLength = nums.size();
        int dp[numsLength];
        int result = nums[0];
        
        if (nums[0] < 0)
            dp[0] = 0;
        else
            dp[0] = nums[0];
        
        
        for (int i = 1; i< numsLength; i++)
        {
            dp[i] = dp[i-1] + nums[i];
            if (dp[i] > result)
                result = dp[i];
            if (dp[i] < 0)
                dp[i] = 0;
        }
        return result;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> input = {-2,1,-3,4,-1,2,1,-5,4};
    assert(s.maxSubArray(input) == 6);
    
    return 0;
}
