class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int leftMax = INT_MIN;
        int rightMax = INT_MIN;

        int res = 0;

        while(l <= r)
        {
            if(height[l] <= height[r])
            {
                if(height[l] > leftMax)
                    leftMax = height[l];
                else
                    res += leftMax - height[l];
                l++;
            }
            else
            {
                if(height[r] > rightMax)
                    rightMax = height[r];
                else
                    res += rightMax - height[r];
                r--;
            }
        }

        return res;
    }
};