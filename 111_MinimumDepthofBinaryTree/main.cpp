//
//  main.cpp
//  111_MinimumDepthofBinaryTree
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

class Solution {
public:
    int minDepth(TreeNode* root) {
        int leftT = 0;
        int rightT = 0;
        bool isRoot = true;
        
        if (root == NULL){
            return 0;
        }
        if (isRoot == true){
            isRoot = false;
            if (root->left == NULL)
                return minDepth(root->right) + 1;
            if (root->right == NULL)
                return minDepth(root->left) + 1;
        }
        leftT = minDepth(root->left) + 1;
        rightT = minDepth(root->right) + 1;
        
        return min (leftT, rightT);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    TreeNode* result = NULL;
    assert(s.minDepth(result) == 0);
    
    return 0;
}
