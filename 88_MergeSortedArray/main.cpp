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
    /*
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
     */
    /*
     [0]
     0
     [1]
     1
     Output:
     [0]
     Expected:
     [1]
     
     */
    /*
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int finalLength = m + n ;
        int curFinalIndex = finalLength - 1;
        int cur1Index = m - 1;
        int cur2Index = n - 1;
        int cur1Value;
        int cur2Value;

        
        while (cur2Index >= 0 && curFinalIndex >=0 ) {
            //in case array1 is empty and array2 is not empty
            //avoid accessing invalid address of array1 such as array1[-1]
            if (cur1Index < 0) {
                cur1Value = 0;
            } else {
                cur1Value = nums1[cur1Index];
            }
            
            cur2Value = nums2[cur2Index];
            
            if (cur1Value > cur2Value) {
                nums1[curFinalIndex] = cur1Value;
                cur1Index--;
            } else {
                nums1[curFinalIndex] = cur2Value;
                cur2Index--;
            }
            curFinalIndex--;
        }
    }
    
    */
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int finalLength = m + n ;
        int curFinalIndex = finalLength - 1;
        int cur1Index = m - 1;
        int cur2Index = n - 1;
        
        while (cur1Index >= 0 && cur2Index >= 0) {
            if (nums1[cur1Index] > nums2[cur2Index]) {
                nums1[curFinalIndex] = nums1[cur1Index];
                cur1Index--;
            } else {
                nums1[curFinalIndex] = nums2[cur2Index];
                cur2Index--;
            }
            curFinalIndex--;
        }
        
        if (cur1Index < 0 && cur2Index >= 0) {
            while (cur2Index >= 0) {
                nums1[curFinalIndex] = nums2[cur2Index];
                cur2Index--;
                curFinalIndex--;
                
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    /*
     
     More Details
     
     Input:
     [1,2,3,0,0,0]
     3
     [2,5,6]
     3
     Output:
     [1,2,3,0,0,2]
     Expected:
     [1,2,2,3,5,6]
     
     */
    

    vector<int> array1 = {1,2,3,0,0,0};
    vector<int> array2 = {2,5,6};
    int num1 = 3;
    int num2 = 3;
    
    vector<int> array3 = {0,0,3,0,0,0,0,0,0};
    vector<int> array4 = {-1,1,1,1,2,3};
    int num3 = 3;
    int num4 = 6;
    
    Solution s;
   // s.merge(array1, num1, array2, num2);
    s.merge(array3, num3, array4, num4);

    return 0;
}
