//
//  main.cpp
//  169_MajorityElement
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


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curCount = 0;
        int vectorSize = (int)nums.size();
        int majorElement = nums[0];
        
        for(int i = 0; i < vectorSize; i++) {
            if(nums[i] == majorElement) {
                curCount++;
            } else {
                if(curCount == 0){
                    majorElement = nums[i];
                }else{
                    curCount--;
            
                }
            }
        }
        return majorElement;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> outVector = {2,2,1,1,1,2,2};
    // vector<vector<int>> outVector = {{1}, {1,1}};
    assert(s.majorityElement(outVector) == 2);
    return 0;
}
