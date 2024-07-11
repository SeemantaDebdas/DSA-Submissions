class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> numSet;
        for(int i = 0; i < nums.size(); i++)
        {
            numSet.insert(nums[i]);
        }

        int maxCount = 0;
        for(auto i : numSet)
        {
            if(numSet.find(i - 1) != numSet.end())
                continue;
            
            int count = 0;
            int ele = i;
            
            while(numSet.find(ele) != numSet.end())
            {
                count++;
                ele++;
            }

            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};