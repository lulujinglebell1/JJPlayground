//
//  main.cpp
//  155_MinStack
//
//  Created by Jane Jane on 9/10/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>


using namespace std;



class MinStack {
    
private:
    class Node{
        int val;
        Node* next = NULL;
    };
    int minV;
    Node* root;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        root = NULL;
    }
    
    void push(int x) {
        if (root != NULL){
            minV = min(x, minV);
        }else{
            Node* temp = new Node;
            
        }
        
    }
    
    void pop() {
        
    }
    
    int top() {
     
        return 0;
    }
    
    int getMin() {
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
