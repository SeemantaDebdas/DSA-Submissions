class Solution {
public:
    void findSubsets(vector<int> &nums, int index, vector<int>& inner, vector<vector<int>>& outer)
    {
        outer.push_back(inner);

        for(int i = index; i < nums.size(); i++)
        {
            if(i > index && nums[i] == nums[i - 1])
                continue;

            inner.push_back(nums[i]);
            findSubsets(nums, i + 1, inner, outer);
            inner.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        vector<int> inner;
        vector<vector<int>> outer;

        findSubsets(nums, 0, inner, outer);

        return outer;
    }
};