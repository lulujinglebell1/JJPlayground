//
//  main.cpp
//  2_AddTwoNumbers
//
//  Created by Jane Jane on 10/4/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

/*
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 Example:
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 Explanation: 342 + 465 = 807.
 */

/*
 specail case 1: ==>need to consider integer overflow case!!!!
 ==> has to use queue instead of regular math using sum = int+int;
 
 Input:
 [9]
 [1,9,9,9,9,9,9,9,9,9]
 Expected:
 [0,0,0,0,0,0,0,0,0,0,1]
 
 special case 2:
 Input:
 [0]
 [0]
 Expected:
 [0]
 */



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    queue<int> queue1;
    queue<int> queue2;
    queue<int> queueSum;
    int carrier = 0;
    int value1;
    int value2;
    int curSum = -1; //

    ListNode* cur1 = l1;
    ListNode* cur2 = l2;
    
    
    while (cur1 != NULL) {
        queue1.push(cur1->val);
        cur1 = cur1->next;
    }
    
    while (cur2 != NULL) {
        queue2.push(cur2->val);
        cur2 = cur2->next;
    }

    while ((queue1.empty() != true || queue2.empty() != true) || (carrier == 1)) {
        if (queue1.empty() != true) {
            value1 = queue1.front();
            queue1.pop();
        }else {
            value1 = 0;
        }
        
        if (queue2.empty() != true) {
            value2 = queue2.front();
            queue2.pop();
        }else {
            value2 = 0;
        }
        curSum = value1 + value2 + carrier;
        
        if (curSum >= 10) {
            queueSum.push (curSum % 10);
            carrier = 1;
        } else {
            queueSum.push (curSum);
            carrier = 0;
        }
    }
    
    ListNode* returnListHead = new ListNode(queueSum.front());
    queueSum.pop();
    ListNode* curNode = returnListHead;
    
    while (queueSum.empty() != true) {
        ListNode* nextNode = new ListNode(queueSum.front());
        queueSum.pop();
        curNode->next = nextNode;
        curNode = nextNode;
    }
    
    return returnListHead;
}
    

int main(int argc, const char * argv[]) {
    
    ListNode head1(9);
    head1.next = NULL;
    
    ListNode head(1);
    ListNode child1(9);
    head.next = &child1;
    ListNode child2(9);
    child1.next = &child2;
    ListNode child3(9);
    child2.next = &child3;
    ListNode child4(9);
    child3.next = &child4;
    ListNode child5(9);
    child4.next = &child5;
    ListNode child6(9);
    child5.next = &child6;
    ListNode child7(9);
    child6.next = &child7;
    ListNode child8(9);
    child7.next = &child8;
    ListNode child9(9);
    child8.next = &child9;
    child9.next = NULL;
    
    ListNode head2(2);
    ListNode child12(4);
    head2.next = &child12;
    ListNode child22(3);
    child12.next = &child22;
    child22.next = NULL;
    
    ListNode head3(5);
    ListNode child13(6);
    head3.next = &child13;
    ListNode child23(4);
    child13.next = &child23;
    child23.next = NULL;
    
    //addTwoNumbers(&head1, &head);
    addTwoNumbers(&head2, &head3);

    
    return 0;
}

