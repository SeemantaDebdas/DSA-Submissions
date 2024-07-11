class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int start = nums[0];

        int slow = start;
        int fast = start;

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);

        fast = start;

        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};