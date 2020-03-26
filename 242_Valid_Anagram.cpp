/*
#include<iostream>
#include<assert.h>
#include<string>
#include<map>
using namespace std;
*/

/*
Problem #242
Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

class Solution {
public:

	bool isAnagram(string s, string t) {
		map <char, int> trackMap;
		if (s.size() != t.size())
		{
			return false;
		}

		for (int i = 0; i < s.size(); i++)
		{
			trackMap[s[i]] ++;
		}

		for (int j = 0; j < t.size(); j++)
		{
			if (trackMap[t[j]] > 0)
			{
				trackMap[t[j]]--;
			}
			else
			{
				return false;
			}
			

		}
		return true;
	}

};

/*
int main() {
	Solution s;
	string input1 = "anagram";
	string input2 = "nagaram";

	assert(s.isAnagram(input1, input2 ) == true);

	return 0;
}
*/



