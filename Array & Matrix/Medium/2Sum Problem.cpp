class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> subMap;

        for(int i = 0; i < nums.size(); i++)
        {
            if(subMap.find(nums[i]) != subMap.end())
                return {subMap[nums[i]], i};
            
            subMap[target - nums[i]] = i;
        }

        return {-1, -1};
    }
};