//
//  main.cpp
//  141_LinkedListCycle
//
//  Created by Jane Jane on 9/19/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>  //find n2
#include <assert.h>
#include <math.h>  //
#include <set>  //

using namespace std;
struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
    
};

bool hasCycle (ListNode* head){
    
    set <ListNode*> setOfNodes;
    ListNode* curNode = head;
    
    while (curNode != NULL){
        if (setOfNodes.count (curNode) == 1){
            return true;
        }else{
            setOfNodes.insert(curNode);
            curNode = curNode->next;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
