//
//  main.cpp
//  88_MergeSortedArray
//
//  Created by Jane Jane on 8/21/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

/*
 Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 
 Note:
 
 The number of elements initialized in nums1 and nums2 are m and n respectively.
 You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
 Example:
 
 Input:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6],       n = 3
 
 Output: [1,2,2,3,5,6]
 */

#include <iostream>
#include <assert.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        stack <int> sortS;
        int index1 = m-1;
        int index2 = n-1;
        int returnI = 0;
        
        if (n == 0)
            return;
        
        
        if (m == 0)
        {
            for (int i = 0; i <= index2; i++)
            {
                nums1[i] = nums2[i];
            }
            return;
        }
        
        
        while (index1 >= 0 || index2 >= 0)
        {
            
            if (nums1[index1] <= nums2[index2] )
            {
                sortS.push(nums2[index2]);
                index2--;
            }
            else
            {
                sortS.push(nums1[index1]);
                index1--;
            }
            
        }
        
        while (sortS.empty() != true)
        {
            returnI ++;
            nums1[returnI] = sortS.top();
            sortS.pop();
            
        }
        
        return;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> array1 = {1};
    vector<int> array2 = {};
    int num1 = 1;
    int num2 = 0;
    
    
    Solution s;
    s.merge(array1, num1, array2, num2);
    

    //assert(s.merge(2) == 2);

    return 0;
}
