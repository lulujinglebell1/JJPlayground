//
//  main.cpp
//  15_3Sum
//
//  Created by Jane Jane on 8/2/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
#include <set>
using namespace std;

/*
 Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

 Note:

 The solution set must not contain duplicate triplets.

 Example:

 Given array nums = [-1, 0, 1, 2, -1, -4],

 A solution set is:
 [
   [-1, 0, 1],
   [-1, -1, 2]
 ]
 */

//change it to a two sum question

//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> output;
//        map<int, int> valuePairIndex;
//        map<int, int> valuePairIndexDuplicate;
//        int cur2SumTarget;
//        int curTarget;
//        vector<int> subResult;
//        int zeroCount = 0;
//
//        //if input element less than 3, output [] {0,0}
//        if (nums.size() < 3) {
//            return output;
//        }
//
//        for (int i = 0; i < nums.size(); i++) {
//            cur2SumTarget = nums[i];
//            //coner case#1: handle special cases where all the element is 0 {0,0,0....} or {0}
//            if (cur2SumTarget == 0) {
//                zeroCount++;
//                if (zeroCount == nums.size() && zeroCount >= 3) {
//                    return {{0,0,0}};
//                }
//            }
//            //make sure the first pair is not missing
//            if (i==0) {
//                valuePairIndex[nums[0]] = 0;
//                printf("value:%d, Index:%d \n", nums[i], i);
//            }
//
//            //change to a two sum question:
//            for (int j = i+1; j < nums.size(); j++) {
//
//                curTarget = (-cur2SumTarget) - nums[j];
//
//                if (valuePairIndex.count(nums[j]) == 0) {
//                    valuePairIndex[nums[j]] = j; //we dont overwrite the index, FCFS
//                    printf("value:%d, Index:%d \n", nums[j], j);
//                } else {
//                    valuePairIndexDuplicate[nums[j]] = j; //we store the value which has seen before, this could overwrite tho in the current 2 sum process
//                    printf("Duplicated value:%d, Index:%d \n", nums[j], j);
//                }
//
//                if((valuePairIndex.count(curTarget)) && //found the curTarget value in the map
//                    (valuePairIndex[curTarget] >= i)) //to avoid duplication, need to ignore all the cur2SumTarget which has been handled before
//                {
//                    //case#1:
//                    if ((valuePairIndex[curTarget] == j) && (valuePairIndexDuplicate.count(nums[j]) == 0))
//                        //the target can be itself if there are more than 2 element in the array
//                        {continue;}
//
////                    //case#2:
////                    if (valuePairIndexDuplicate.count(nums[j]) != 0)
////                    {
////                        if (nums[j] + curTarget + nums[i] != 0)
////                        //if the same element has been handled as i before, skip it unless itself + itself = nums[i]
////                        //example: Input [-1,0,1,2,-1,-4], output ["[-1,-1,2]",[-1,0,1]]-->(nums[i]=2,nums[j]=-1)
////                        {continue;}
////
//////                        Input [-1,0,1,2,-1,-4]
//////                        Output [[-1,1,0]]
//////                        Expected ["[-1,-1,2]",[-1,0,1]]
////                    }
//
//                    //case#3:
//                    //the target is on index i, but there are no duplication of the value in index i in the input, then we should skip it
//                    //Input [1,1,-2]
//                    if ((valuePairIndex[curTarget] == i) && (valuePairIndexDuplicate.count(curTarget) == 0))
//                    {continue;}
//
//                    //case#4:
//                    //input [-1,0,1,0], error Output [[-1,1,0],[0,0,0]]
//                    if (((valuePairIndexDuplicate.count(nums[j]) !=0)) && (nums[j] == 0) && (zeroCount < 3))
//                    {continue;}
//
//                    subResult.push_back(cur2SumTarget);
//                    subResult.push_back(nums[j]);
//                    subResult.push_back(curTarget);
//                    output.push_back(subResult);
//                    subResult.clear();
//                }
//            }
//        }
//
//        return output;
//    }
//};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int,int> posMap;
        unordered_map<int,int> negMap;
        int zeroCount = 0;
        
        // Seggregate possitive and negative in seperate maps
        for (auto &n : nums) {
            if (n == 0) {
                zeroCount++;
            } else if (n > 0) {
                posMap[n]++;
            } else
                negMap[n]++;
        }
        if (zeroCount >= 3)
            result.push_back({0,0,0});
        
        for (auto &n: posMap) {
            // If zero found in the array then just search for mirror
            // negative element
            if (zeroCount) {
                if (negMap.count(-n.first))
                    result.push_back({-n.first,0,n.first});
            }
            for (auto &m : negMap) {
                // If number has frequency of more than 2
                if (m.second >= 2) {
                    int sum = n.first + 2*(m.first);
                    if (sum == 0)
                        result.push_back({m.first,m.first,n.first});
                }
                
                // If number has frequency of more than 2
                if (n.second >= 2) {
                    int sum = 2*n.first + m.first;
                    if (sum == 0) {
                        cout << "dup result added" << endl;
                        result.push_back({m.first,n.first,n.first});
                    }
                }
                
                // Inorder to avoid duplicates follow one consistent approach
                // we will cross search only if remaining part of sum if is greater
                // the current sum. This simply helps to avoid the duplicates
                int remSum = 0 - (n.first + m.first);
                if (remSum > n.first) {
                    if (posMap.count(remSum)) {
                        result.push_back({m.first,n.first,remSum});
                    }
                }
                if (remSum > m.first) {
                    if (negMap.count(remSum)) {
                        result.push_back({m.first,remSum,n.first});
                    }
                }
            }
        }
    
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    
    vector<int> input = {-1,0,1,2,-1,-4};
    vector<vector<int>> output = {{-1,-1,2},{-1,0,1}};
   //assert (s.threeSum(input) == output);

    vector<int> input1 = {0,0,0};
    vector<vector<int>> output1 = {{0,0,0}};
    //assert (s.threeSum(input1) == output1);
 
    vector<int> input2 = {-1,0,1};
    vector<vector<int>> output2 = {{-1,0,1}};
 //   assert (s.threeSum(input2) == output2);
    
    
    vector<int> input3 = {1,1,-2};
    vector<vector<int>> output3 = {{1,1,-2}};
  // assert (s.threeSum(input3) == output3);
    
     vector<int> input4 = {0,-1,1};
     vector<vector<int>> output4 = {{0,1,-1}};
   //  assert (s.threeSum(input4) == output4);
    
    vector<int> input5 = {-2,0,1,1,2};
    vector<vector<int>> output5 = {{-2,0,2},{-2,1,1}};
    //assert (s.threeSum(input5) == output5);
    
    
    return 0;
}
