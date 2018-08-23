//
//  main.cpp
//  121_BestTimetoBuyandSellStock
//
//  Created by Jane Jane on 8/22/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;
/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 
 Note that you cannot sell a stock before you buy one.
 
 Example 1:
 
 Input: [7,1,5,3,6,4]
 dp:    [7,1,1,1,1,
 result:[0,0,4,4,
 Output: 5
 Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 Not 7-1 = 6, as selling price needs to be larger than buying price.
 Example 2:
 
 Input: [7,6,4,3,1]
 Output: 0
 Explanation: In this case, no transaction is done, i.e. max profit = 0.
 
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        unsigned int inputSize = prices.size();
        
        if (inputSize == 0)
            return 0;
        
        int dp[inputSize];
        
        for(int i = 0; i < inputSize; i++)
        {
            if (i == 0)
            {
                result = 0;
                dp[0] = prices[0];
            }
            else
            {
                if (dp[i-1] > prices[i])
                {
                    dp[i] = prices[i];
                }
                else
                {
                    dp[i] = dp[i-1];
                    result = max (result, prices[i] - dp[i-1]);
                }
            }
            printf("dp %d ", dp[i]);
            printf("result %d ", result);
            
        }
        return result;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> input = {7, 1, 5, 3, 6, 4};
    assert(s.maxProfit(input) == 5);
    
    return 0;
}
