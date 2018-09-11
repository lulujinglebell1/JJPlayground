//
//  main.cpp
//  110_BalancedBinaryTree
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

int treeHight (TreeNode* root, bool& flag)
{
    if (root == NULL){
        return 0;
    }
    int leftH = treeHight(root->left, flag) + 1;
    int rightH = treeHight(root->right, flag) + 1;
    
    if (abs(leftH - rightH) > 1)
        flag = false;
    return max(leftH, rightH);
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        treeHight(root, flag);
        return flag;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    TreeNode* result = NULL;
    assert(s.isBalanced(result) == true);
    return 0;
}
