//
//  main.cpp
//  108_ConvertSortedArraytoBinarySearchTree
//
//  Created by Jane Jane on 9/9/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

/*
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 
 Example:
 
 Given the sorted array: [-10,-3,0,5,9],
 
 One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 
 0
 / \
 -3   9
 /   /
 -10  5
 */


//Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* createTree (vector<int>& nums, int leftStart, int rightStart)
{
    int vectorLen = rightStart - leftStart;
    int mid = leftStart + vectorLen/2;
    
    if (rightStart < leftStart ){
        return NULL;
    }
    
    TreeNode* newNode =  new TreeNode(nums[mid]);
    newNode->left = createTree (nums, leftStart, mid-1);
    newNode->right = createTree (nums, mid+1, rightStart );
    return newNode;
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* newNode = createTree (nums, 0, (int) nums.size()-1);
        return newNode;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    TreeNode* result = NULL;
    vector <int> stringInput = {-10,-3,0,5,9};
    assert(s.sortedArrayToBST(stringInput) == result);
    return 0;
}
