//
//  main.cpp
//  172_FactorialTrailingZeroes
//
//  Created by Jane Jane on 9/20/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        long long result = 1;
        int zero = 0;
        
        for (int i = n; i >= 1; i--){
            result = result*i;
        }
        
        while (result % 10 == 0){
            zero++;
            result = result / 10;
        }
        return zero;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    
    assert(s.trailingZeroes(13) == 2);
    return 0;
    return 0;
}
