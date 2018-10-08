
//  main.cpp
//  2_AddTwoNumbers
//
//  Created by Jane Jane on 10/4/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>

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
/*
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 

long int Increment10 (int time10) {
    long int result  = 1;
    if (time10 == 0)
    {
        return 1;
    } else {
        for (int i = 1; i <= time10; i++) {
            result = result * 10;
        }
    }
    return result;
}
long int listToNum (ListNode* inList)
{
    ListNode* curN = inList;
    long int returnInt = 0;
    int time10 = 0;
    while (curN != NULL)
    {
        returnInt = returnInt + (curN->val)* Increment10(time10);
        time10++;
        curN = curN->next;
    }
    return returnInt;
}

ListNode* numToList (long num)
{

    long curNum = num;
    ListNode* returnN = NULL;
    ListNode* curN = NULL;
    int firstN = true;
    
    if (num == 0) {
        returnN = new ListNode(0);
        return returnN;
    }
    
    while (curNum != 0)
    {
        if (firstN == true)
        {
            returnN = new ListNode(curNum%10);
            firstN = false;
            curN = returnN;
        }
        else
        {
            curN->next = new ListNode(curNum%10);
            curN = curN->next;
        }
        curNum = curNum/10;
    }
    return returnN;
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* returnList;
        long sum;
        sum = listToNum (l1) + listToNum (l2);
        returnList = numToList (sum);
        return returnList;
    }

};

int main(int argc, const char * argv[]) {
    /*
    ListNode head(2);
    ListNode child1(4);
    head.next = &child1;
    ListNode child2(3);
    child1.next = &child2;
    child2.next = NULL;
    
    ListNode head2(5);
    ListNode child12(6);
    head2.next = &child12;
    ListNode child22(4);
    child12.next = &child22;
    child22.next = NULL;
    */
    /*
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
    
    addTwoNumbers(&head1, &head);
    
    return 0;
}
*/
