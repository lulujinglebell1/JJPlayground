//
//  main.cpp
//  198_HouseRobber
//
//  Created by JJ  on 3/8/20.
//  Copyright © 2020 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
 You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

 Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

 Example 1:

 Input: [1,2,3,1]
 Output: 4
 Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
              Total amount you can rob = 1 + 3 = 4.
 Example 2:

 Input: [2,7,9,3,1]
 Output: 12
 Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
              Total amount you can rob = 2 + 9 + 1 = 12.
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        //make use of dynamic programming
        int inputSize = (int)nums.size();
        vector<int> dp(inputSize);
        
        int index = 2;
        int maxMoney = 0;
        
        //handle special case first
        if (inputSize == 0) {
            return 0;
        }
        
        if (inputSize == 1) {
            return nums[0];
        }
        
        if (inputSize == 2) {
            return max(nums[0],nums[1]);
        }
        
        //when there are more than 2 items on the vector array
        /*
         Approach #1 (Dynamic Programming) [Accepted]

         Algorithm

         It could be overwhelming thinking of all possibilities on which houses to rob.

         A natural way to approach this problem is to work on the simplest case first.

         Let us denote that:

         f(k) = Largest amount that you can rob from the first k houses.
         Ai = Amount of money at the ith house.
         Let us look at the case n = 1, clearly f(1) = A1.

         Now, let us look at n = 2, which f(2) = max(A1, A2).

         For n = 3, you have basically the following two options:

         Rob the third house, and add its amount to the first house's amount.

         Do not rob the third house, and stick with the maximum amount of the first two houses.

         Clearly, you would want to choose the larger of the two options at each step.

         Therefore, we could summarize the formula as following:

         f(k) = max(f(k – 2) + Ak, f(k – 1))
         We choose the base case as f(–1) = f(0) = 0, which will greatly simplify our code as you can see.

         The answer will be calculated as f(n). We could use an array to store and calculate the result, but since at each step you only need the previous two maximum values, two variables are suffice.
         */
        dp[0] = nums[0];
        dp[1] = max (nums[0], nums[1]);
        
        while (index < nums.size()) {
            maxMoney = max ((dp[index-2] + nums[index]), dp[index-1]);
            dp[index] = maxMoney;
            index++;
        }
        return maxMoney;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
