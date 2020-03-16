//
//  main.cpp
//  1_TwoSum
//
//  Created by JJ  on 3/11/20.
//  Copyright © 2020 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> number;
        vector<int> result;
        
        for(int i = 0; i<nums.size(); i++){
            int tag = target-nums[i];
            
            if(number.count(tag) && number[tag] !=i){
                result.push_back(i);
                result.push_back(number[tag]);
                break;
            }
            
            number[nums[i]] = i;
        }
        return result;
    }
};


int main(int argc, const char * argv[]) {

    return 0;
}
