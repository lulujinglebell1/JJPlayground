//
//  main.cpp
//  112_PathSum
//
//  Created by Jane Jane on 9/9/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

bool hasPathTotal(TreeNode* root, int sum, int total){
    int curTotal;
    if (root == NULL){
        return false;
    }
    curTotal = root->val + total;
    if ((curTotal == sum) && (root->left == NULL) && (root->right == NULL)){
        return true;
    }else{
        return hasPathTotal(root->left, sum, curTotal) || hasPathTotal(root->right, sum, curTotal);
    }
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        int total = 0;
        return hasPathTotal(root, sum, total);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    TreeNode* result = NULL;
    int sum = 0;
    assert(s.hasPathSum(result, sum) == false);
    return 0;
}
