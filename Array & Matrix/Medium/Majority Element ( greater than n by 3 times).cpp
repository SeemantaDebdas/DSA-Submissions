class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> res;
        
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int count1 = 0, count2 = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            int ele = nums[i];
            if(count1 == 0 && ele != ele2)
            {
                ele1 = ele;
                count1 = 1;
            }
            else if(count2 == 0 && ele != ele1)
            {
                ele2 = ele;
                count2 = 1;
            }
            else if(ele == ele1)
            {
                count1++;
            }
            else if(ele == ele2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == ele1)
                count1++;
            if(nums[i] == ele2)
                count2++;
        }

        if(count1 > nums.size() / 3)
            res.push_back(ele1);
        
        if(count2 > nums.size() / 3)
            res.push_back(ele2);

        return res;
    }
};