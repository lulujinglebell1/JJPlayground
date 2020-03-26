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
