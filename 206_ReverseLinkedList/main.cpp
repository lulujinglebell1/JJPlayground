//
//  main.cpp
//  206_ReverseLinkedList
//
//  Created by Jane Jane on 10/4/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <stack>

using namespace std;

/*
 Reverse a singly linked list.
 
 Example:
 
 Input: 1->2->3->4->5->NULL
 Output: 5->4->3->2->1->NULL
 Follow up:
 
 A linked list can be reversed either iteratively or recursively. Could you implement both?
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* cur = head;
    ListNode* returnHead = NULL;
    stack <ListNode*> nodeStack;
    
    if (head == NULL) {
        return NULL;
    }
    
    while (cur != NULL) {
        nodeStack.push (cur);
        cur = cur->next;
    }
    
    returnHead = nodeStack.top();
    nodeStack.pop();
    cur = returnHead;
    
    while (cur != head) {
        cur->next = nodeStack.top();
        nodeStack.pop();
        cur = cur->next;
    }
    cur->next = NULL;
    
    return returnHead;
}

int main(int argc, const char * argv[]) {

    ListNode head(1);
    
    ListNode child1(2);
    head.next = &child1;
    ListNode child2(3);
    child1.next = &child2;
    ListNode child3(4);
    child2.next = &child3;
    ListNode child4(5);
    child3.next = &child4;
    child4.next = NULL;
    
    reverseList(&head);
    
    return 0;
}
