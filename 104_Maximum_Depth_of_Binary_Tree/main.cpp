//
//  main.cpp
//  104_Maximum_Depth_of_Binary_Tree
//
//  Created by Jane Jane on 8/8/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <assert.h>

/*
 Given a binary tree, find its maximum depth.
 
 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 
 Note: A leaf is a node with no children.
 
 Example:
 
 Given binary tree [3,9,20,null,null,15,7],
 
 3
 / \
 9  20
 /  \
 15   7
 return its depth = 3.
 
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

TreeNode* convertArrayToTree (int* inputArray)
{
    
    return NULL;
    
}


int helper (TreeNode * curN)
{
    if (curN == NULL)
        return 0;
    if (curN->left == NULL && curN->right == NULL)
        return 1;
    
    if ((curN->left != NULL) || (curN->right != NULL))
    {
        if (helper (curN->left) >= helper (curN->right))
            return helper (curN->left) + 1;
        else
            return helper (curN->right) + 1;
    }
    return 0;  //?
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return helper (root);
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    int inputTree = [3,9,20,null,null,15,7];
//    assert(s.maxDepth(2) == 2);
//    assert(s.maxDepth(3) == 3);
//    assert(s.maxDepth(4) == 5);
    
    return 0;
}
