class Solution {
public:
    void Merge(vector<int>& nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
            }
        }

        while(left <= mid)
        {
            temp.push_back(nums[left++]);
        }

        while(right <= high)
        {
            temp.push_back(nums[right++]);
        }

        for(int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }
    }

    int CountPairs(vector<int>& nums, int low, int mid, int high)
    {
        int count = 0, right = mid + 1;
        for(int i = low; i <= mid; i++)
        {
            while(right <= high && nums[i] > 2LL * nums[right])//2LL = (long long)2.
            {
                right++;
            }
            count += (right - (mid + 1));
        }

        return count;
    }

    int MergeSort(vector<int> & nums, int low, int high)
    {
        int count = 0;
        if(low < high)
        {
            int mid = (high + low)/2;
            count += MergeSort(nums, low, mid);
            count += MergeSort(nums, mid + 1, high);

            count += CountPairs(nums, low, mid, high);

            Merge(nums, low, mid, high);
        }

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return MergeSort(nums, 0, nums.size() - 1);
    }
};