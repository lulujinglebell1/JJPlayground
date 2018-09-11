//
//  main.cpp
//  118_PascalsTriangle
//
//  Created by Jane Jane on 9/9/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

/*
 Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 
 In Pascal's triangle, each number is the sum of the two numbers directly above it.
 
 Example:
 
 Input: 5
 Output:
 [
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 ]
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {};
        vector<int> rowVector = {};
        
        for(int i = 0; i < numRows; i++){
            if(numRows == 1 || numRows ==2){
                for(int j = 0; j <= i; j++){
                    rowVector.push_back(1);
                }
                result.push_back(rowVector);
                rowVector.clear();
            }else{
                for(int j = 0; j <= i; j++){
                    if (j == 0 || j == i){
                        rowVector.push_back(1);
                    }else{
                        int sum = result[i-1][j-1] + result[i-1][j];
                        rowVector.push_back(sum);
                    }
                }
                result.push_back(rowVector);
                rowVector.clear();
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<vector<int>> outVector = {{1}, {1,1}, {1,2,1}};
   // vector<vector<int>> outVector = {{1}, {1,1}};
    assert(s.generate(3) == outVector);
    return 0;
}
