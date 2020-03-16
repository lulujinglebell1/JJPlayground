//
//  main.cpp
//  17_LetterCombinationsOfAPhoneNumber
//
//  Created by JJ  on 3/14/20.
//  Copyright © 2020 Jane Jane. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;

/*
 Related topic: string & backtracking
 
 Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 
 Example:

 Input: "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

class Solution {
public:
    unordered_map<char,vector<char>> v;
    Solution() {
        v['2']={'a','b','c'};
        v['3']={'d','e','f'};
        v['4']={'g','h','i'};
        v['5']={'j','k','l'};
        v['6']={'m','n','o'};
        v['7']={'p','q','r','s'};
        v['8']={'t','u','v'};
        v['9']={'w','x','y','z'};
    }
    ////////////////////solution#1 using backtracking and recursion
    void letters(string &digits,vector<string> &ans,int i,string &temp)
    {
        if(i>=digits.length())
            ans.push_back(temp);
        for(int j=0;j<v[digits[i]].size();j++)
        {
            string s=string(1,v[digits[i]][j]);
            printf("current char is %c\n", v[digits[i]][j]);
            temp.append(s);
            letters(digits,ans,i+1,temp);
            temp.pop_back();
        }
    }
    vector<string> d_letterCombinations(string digits) {
        vector<string> ans;
        if(digits=="") return ans;
        string temp;
        letters(digits,ans,0,temp);
        return ans;
    }
    
    /////////////solution#2: implemented by Johnny using for loop
    vector<string> letterCombinations(string digits) {
        vector<string> resultsVector;
        
        if(digits=="") { return resultsVector; }
        
        vector<vector<char>> subV;
        vector<int> subVIndices;
        // Construct subset from input--create a new matrix with only the input digit
        for (int i = 0; i < digits.size(); i++) {
            subV.push_back(v[digits[i]]);
            subVIndices.push_back(0);
        }
        
        // Construct result --> create an array to keep track of the current output index of each element
        do {
            string result = "";
            for (int i = 0; i < subV.size(); i++) {
                result.push_back(subV[i][subVIndices[i]]);
            }
            resultsVector.push_back(result);
            // increment indices
        }while(incrementSubVIndices(subV, subVIndices));

        return resultsVector;
    }
    
private:
    bool incrementSubVIndices(vector<vector<char>> &subV, vector<int> &subVIndices) {
        int incrementIndex = (int)subVIndices.size() - 1;
        for (int i = incrementIndex; i >= 0; i--) {
            subVIndices[i]++;
            if (subVIndices[i] < subV[i].size()) {
                return true;
            } else {
                subVIndices[i] = 0;
            }
        }
        return false;
    }
    
};

int main(int argc, const char * argv[]) {

    Solution s;
    vector<string> output = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    assert(s.letterCombinations("23") == output);
    return 0;
}
