
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

/*
 Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
 
 Note that the row index starts from 0.
 
 
 In Pascal's triangle, each number is the sum of the two numbers directly above it.
 
 Example:
 
 Input: 3
 Output: [1,3,3,1]
 Follow up:
 
 Could you optimize your algorithm to use only O(k) extra space?
 */

/*
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
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rowVector = {};
        vector<int> lastVector = {};

        if(rowIndex == 0){
            rowVector.push_back(1);
            return rowVector;
        }
        lastVector.push_back(1);
        lastVector.push_back(1);
        
        if(rowIndex == 1){
            return lastVector;
        }
        
        for(int i = 2; i <= rowIndex; i++){
            for(int j = 0; j <= i; j++){
                if (j == 0 || j == i){
                    rowVector.push_back(1);
                }else{
                    int sum = lastVector[j-1] + lastVector[j];
                    rowVector.push_back(sum);
                }
            }
            lastVector.clear();
            lastVector = rowVector;
            rowVector.clear();
        }
        return lastVector;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> outVector = {1,3,3,1};
    //vector<int> outVector = {1,2, 1};
    //vector<int> outVector = {1,2};

    assert(s.getRow(3) == outVector);
    return 0;
}

