//
//  main.cpp
//  70_ClimbingStairs
//
//  Created by Jane Jane on 8/7/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <assert.h>

/*
 You are climbing a stair case. It takes n steps to reach to the top.
 
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 
 Note: Given n will be a positive integer.
 
 Example 1:
 
 Input: 2
 Output: 2
 Explanation: There are two ways to climb to the top.
 1. 1 step + 1 step
 2. 2 steps
 Example 2:
 
 Input: 3
 Output: 3
 Explanation: There are three ways to climb to the top.
 1. 1 step + 1 step + 1 step
 2. 1 step + 2 steps
 3. 2 steps + 1 step
 
 Input: 4
 Output: 5
 Explanation: There are three ways to climb to the top.
 1. 1 step + 1 step + 1 step + 1 step
 2. 1 step + 2 steps + 1 step
 3. 2 steps + 1 step + 1 step
 4. 1 step + 1 step + 2 step
 5. 2 steps + 2 step
 
 */

//input: 1 2 3 4
//dp   : 1 2 3 5

class Solution {
public:
    int climbStairs(int n) {
        int dp [n+1];
        int result = 0;
        
        if (n == 0 || n == 1 || n == 2 )
            return n;
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
            result = dp[i];
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    
    assert(s.climbStairs(2) == 2);
    assert(s.climbStairs(3) == 3);
    assert(s.climbStairs(4) == 5);
    return 0;
}
