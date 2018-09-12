//
//  main.cpp
//  160_IntersectionofTwoLinkedLists
//
//  Created by Jane Jane on 9/11/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>  //find n2
#include <assert.h>
#include <math.h>  //
#include <set>  //


using namespace std;
struct ListNode;


/*
 LEARN: Compare my code which does not work and takes forever to debug with Johnny's code-- very easy to understand
 1: Dont change the length
 2: when there is a if, always have else, even nothing on the else
 3: Meke the code readable, so that it is easier to debug
 4: comment
 5: DO NOT CODE LIKE INDIAN!!!! -- MAKE YOUR PARTNER NUT!!!!!!!!
 */

/*
class HashTable {
public:
    static unsigned int hashFunction(int input);
    bool insert(ListNode *node);
    bool find(ListNode* node);
    
private:
    typedef struct {
        ListNode* node;
        ListNode* next;
    }HashTableNode;
    // TODO: to optimized hash table size.
    HashTableNode *m_hashTable[128];
}
*/

/*
 Write a program to find the node at which the intersection of two singly linked lists begins.
 
 For example, the following two linked lists:
 
 A:          a1 → a2
 ↘
 c1 → c2 → c3
 ↗
 B:     b1 → b2 → b3
 begin to intersect at node c1.
 
 
 Notes:
 
 If the two linked lists have no intersection at all, return null.
 The linked lists must retain their original structure after the function returns.
 You may assume there are no cycles anywhere in the entire linked structure.
 Your code should preferably run in O(n) time and use only O(1) memory.
 */

/*
 struct ListNode{
 int val;
 ListNode* next;
 ListNode(int x): val(x), next(NULL){}
 };
 
 ListNode* gerIntersectionNode(ListNode* headA, ListNode* headB){
 int lenA = 0;
 int lenB = 0;
 int lenDiff = 0;
 ListNode* curA = headA;
 ListNode* curB = headB;
 
 while (curA != NULL){
 curA = curA->next;
 lenA++;
 }
 
 while (curB != NULL){
 curB = curB->next;
 lenB++;
 }
 
 if (lenA > lenB){
 lenDiff = lenA - lenB;
 while (lenA > lenB){
 curA = curA->next;
 lenA--;
 }
 }
 
 if(lenA < lenB){
 lenDiff = lenB - lenA;
 while (lenB > lenA){
 curB = curB->next;
 lenB--;
 }
 }
 while (curA != curB && curA != NULL){
 curA = curA->next;
 curB = curB->next;
 }
 if (curA == NULL){
 return NULL;
 }
 return curA;
 }
 
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 1;
        int lenB = 1;
        ListNode* curA = headA;
        ListNode* curB = headB;
        
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        
        while (curA != NULL){
            curA = curA->next;
            lenA++;
        }
        
        while (curB != NULL){
            curB = curB->next;
            lenB++;
        }
        
        ListNode* longerList = NULL;
        ListNode* shorterList = NULL;
        int lenDiff = abs(lenA - lenB);
        
        if (lenA > lenB){
            longerList = headA;
            shorterList = headB;
        } else {
            shorterList = headA;
            longerList = headB;
        }
        
        for (int i = 0; i < lenDiff; i++) {
            longerList = longerList->next;
        }
        
        // LongerList will have same length as ShorterList now
        while (longerList != NULL && shorterList != NULL) {
            if (longerList == shorterList) {
                return longerList;
            }
            
            longerList = longerList->next;
            shorterList = shorterList->next;
        }
        
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
