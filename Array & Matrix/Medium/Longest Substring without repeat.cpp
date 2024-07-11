class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<int, int> charMap;

        int left = 0, right = 0;
        int len, maxLen = 0;
        while(left <= right && right < s.size())    
        {
            if(charMap.find(s[right]) != charMap.end())
            {
                if(charMap[s[right]] >= left)
                    left = charMap[s[right]] + 1;
            }

            maxLen = max(right - left + 1, maxLen);
            charMap[s[right]] = right;
            right++;
        }

        return maxLen;
    }
};