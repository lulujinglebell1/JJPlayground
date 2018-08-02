//
//  main.cpp
//  3_LongestSubstringWithoutRepeatingCharacters
//
//  Created by Jane Jane on 8/1/18.
//  Copyright © 2018 Jane Jane. All rights reserved.
//

/*
 Given a string, find the length of the longest substring without repeating characters.
 
 Examples:
 
 Given "abcabcbb", the answer is "abc", which the length is 3.
 
 Given "bbbbb", the answer is "b", with the length of 1.
 
 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <iostream>
#include <string.h>
#include <assert.h>

#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unsigned long inputStringLength = s.size();
        map<char, int> map;
        
        int longestLength = 0;
        for (int i = 0, j = 0; j < inputStringLength; j++) {
            char charCurr = s[j];
            if (map.find(charCurr) != map.end()) {
                // find repeated charater
                i = max(map[charCurr] + 1, i);
            }
            map[charCurr] = j;
            longestLength = max(j - i + 1, longestLength);
        }
        
        return longestLength;
    }
    
    int lengthOfLongestSubstringFast(string s) {
        unsigned long inputStringLength = s.size();
        int map[128];
        memset(map, -1, 128 * sizeof(*map));
        
        int longestLength = 0;
        for (int i = 0, j = 0; j < inputStringLength; j++) {
            char charCurr = s[j];
            if (map[charCurr] != -1) {
                // find repeated charater
                i = max(map[charCurr] + 1, i);
            }
            map[charCurr] = j;
            longestLength = max(j - i + 1, longestLength);
        }
        
        return longestLength;
    }

};


int main(int argc, const char * argv[]) {
    
    Solution s;
    
    assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(s.lengthOfLongestSubstring("bbbbb") == 1);
    assert(s.lengthOfLongestSubstring("pwwkew") == 3);
    assert(s.lengthOfLongestSubstring("abba") == 2);

    assert(s.lengthOfLongestSubstringFast("abcabcbb") == 3);
    assert(s.lengthOfLongestSubstringFast("bbbbb") == 1);
    assert(s.lengthOfLongestSubstringFast("pwwkew") == 3);
    assert(s.lengthOfLongestSubstringFast("abba") == 2);

    return 0;
}
