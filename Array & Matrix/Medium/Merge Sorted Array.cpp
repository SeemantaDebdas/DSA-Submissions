class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        //we'll be going from the back and inputing the bigger numbers
        while(j >= 0)//until j is finished since nums1 will already be sorted.
        {
            if(i >= 0 && nums1[i] > nums2[j])//if equal j will get priority since we need to exhaust nums2
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
    }
};